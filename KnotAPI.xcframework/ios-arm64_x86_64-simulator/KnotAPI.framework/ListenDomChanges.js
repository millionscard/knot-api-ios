function debounce(fn, wait) {
  let t;
  return function (...args) {
    clearTimeout(t);
    t = setTimeout(() => fn.apply(this, args), wait);
  };
}

function sendEvent(type, detail) {
  const payload = JSON.stringify(
    Object.assign({ type, ts: Date.now() }, detail || {})
  );
  if (window.JSInterface && window.JSInterface.domChanged) {
    window.JSInterface.domChanged(payload);
  }

  if (window.webkit?.messageHandlers?.domChanged) {
    window.webkit?.messageHandlers?.domChanged.postMessage(payload);
  }
}

// SCROLL EVENT
window.addEventListener(
  'scroll',
  debounce(() => {
    sendEvent('scroll', {
      scrollTop: window.scrollY,
      viewportHeight: window.innerHeight,
      documentHeight: document.documentElement.scrollHeight,
    });
  }, 300),
  { passive: true }
);

// CLICK EVENT
window.addEventListener(
  'click',
  function (e) {
    const t = e.target.closest('*');
    let text = null;
    if (t) {
      const tag = t.tagName;
      if (tag === 'INPUT' || tag === 'TEXTAREA') {
        text =
          t.getAttribute('placeholder') ||
          t.getAttribute('aria-label') ||
          t.getAttribute('name') ||
          '[input_field]';
      } else {
        text = (t.innerText || '').trim().slice(0, 100);
      }
    }
    sendEvent('click', {
      x: e.clientX,
      y: e.clientY,
      tag: t ? t.tagName : null,
      id: t?.id || null,
      cls: t?.className || null,
      isLink: !!t?.closest('a'),
      text: text,
    });
  },
  true
);

// MUTATION OBSERVER
const noisy = ['INPUT', 'TEXTAREA', 'SELECT'];
new MutationObserver(
  debounce((muts) => {
    for (const m of muts) {
      const isNoisy =
        noisy.includes(m.target.nodeName) ||
        (m.type === 'attributes' &&
          ['class', 'style'].includes(m.attributeName)) ||
        [...m.addedNodes, ...m.removedNodes].some((n) =>
          noisy.includes(n.nodeName)
        );
      if (!isNoisy) {
        sendEvent('dom');
        break;
      }
    }
  }, 800)
).observe(document, {
  attributes: true,
  childList: true,
  characterData: true,
  subtree: true,
});

// URL CHANGE DETECTION
window.__lastURL = location.href;
function checkUrl() {
  if (location.href !== window.__lastURL) {
    window.__lastURL = location.href;
    sendEvent('url_change', { href: location.href });
  }
}
['pushState', 'replaceState'].forEach((fn) => {
  const orig = history[fn];
  history[fn] = function (...args) {
    const res = orig.apply(this, args);
    checkUrl();
    return res;
  };
});
window.addEventListener('popstate', checkUrl);
window.addEventListener('hashchange', checkUrl);

// MANUAL SCREENSHOT HOOK
window.requestKnotScreenshot = function (data) {
  sendEvent('custom triggered', data);
};

// INITIAL SCREENSHOT WHEN DOM IS READY
if (
  document.readyState === 'complete' ||
  document.readyState === 'interactive'
) {
  window.requestKnotScreenshot({ type: 'rendered' });
} else {
  window.addEventListener('DOMContentLoaded', function () {
    window.requestKnotScreenshot({ type: 'rendered' });
  });
}
