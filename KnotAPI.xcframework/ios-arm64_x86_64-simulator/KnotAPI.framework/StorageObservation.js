;(function knotRealtimeStorageHook(passedConfig) {
  if (window.__knotStorageHooked) return;
  window.__knotStorageHooked = true;

  // ------------------ Config (global + passed overrides) ------------------
  function getConfig() {
    const globalCfg = (window.__knotStorageConfig && typeof window.__knotStorageConfig === 'object')
      ? window.__knotStorageConfig
      : {};
    const localCfg = (passedConfig && typeof passedConfig === 'object') ? passedConfig : {};
    return Object.assign({
      channel: 'KNOT_STORAGE',
      localStorageRequiredProps: [],
      sessionStorageRequiredProps: [],
      stringifyIOS: false,     // iOS handler expects object by default; set true to stringify
      enableKeyGlobs: true,    // allow '*'/'?' in key patterns
      enableKeyRegex: true,    // allow '/^...$/' regex literals in key patterns
      requireTopFrame: true,   // only hook top window by default (fixes iframe bridge access)
      androidRetryMs: 120000,  // max time to retry bridge attach (2 minutes)
      enableLateWriteCapture: false  // capture storage writes after polling stops (for async auth like MSAL) and
    }, globalCfg, localCfg);
  }

  // ------------------ Top-frame guard (fixed) ------------------
  function topFrameGate() {
    const { requireTopFrame } = getConfig();
    if (!requireTopFrame) return true;
    try { return window.top === window.self; }
    catch { return false; }  // cross-origin => treat as not top
  }
  if (!topFrameGate()) return;

  // ------------------ Breadcrumbs (sendDataToWebApp) ------------------
  function postLogMessage(message, logIdentifier) {
    // Android: JSInterface.sendDataToWebApp(message, id) preferred; one-arg fallback
    if (window.JSInterface?.sendDataToWebApp) {
      try { window.JSInterface.sendDataToWebApp(message, logIdentifier); }
      catch {
        try {
          const merged = JSON.stringify({ __logIdentifier: logIdentifier, __payload: JSON.parse(message) });
          window.JSInterface.sendDataToWebApp(merged);
        } catch {}
      }
    }
    // iOS: sendDataToWebApp({ [id]: message })
    if (window.webkit?.messageHandlers?.sendDataToWebApp?.postMessage) {
      try { window.webkit.messageHandlers.sendDataToWebApp.postMessage({ [logIdentifier]: message }); } catch {}
    }
  }
  const breadcrumbId = 'storage_hook';
  let logCounter = 0;
  function logBreadcrumb(message, type = 'storage_info') {
    const id = 'storage_logs_' + (++logCounter);
    try { postLogMessage(JSON.stringify({ breadcrumbId, message, type }), id); } catch {}
  }

  // ------------------ Utils ------------------
  const isObject = (v) => v !== null && typeof v === 'object';
  const isString = (v) => typeof v === 'string';
  function safeJSONParse(s) { try { return JSON.parse(s); } catch { return undefined; } }

  // dot-path resolver: "a.b.c"
  function resolveDotPath(obj, path) {
    if (!isObject(obj) || !isString(path)) return { exists: false, value: undefined };
    const parts = path.split('.').filter(Boolean);
    let cur = obj;
    for (const p of parts) {
      if (cur == null || !Object.prototype.hasOwnProperty.call(cur, p)) return { exists: false, value: undefined };
      cur = cur[p];
    }
    return { exists: true, value: cur };
  }

  // Optional: glob/regex key matching (for namespaced keys like Cognito*)
  function escapeRegex(s) { return s.replace(/[.*+?^${}()|[\]\\]/g, '\\$&'); }
  function patternToRegex(pat, cfg) {
    if (cfg.enableKeyRegex && pat.length >= 2 && pat.startsWith('/') && pat.endsWith('/')) {
      return new RegExp(pat.slice(1, -1));
    }
    if (cfg.enableKeyGlobs && (pat.includes('*') || pat.includes('?'))) {
      const rx = '^' + escapeRegex(pat).replace(/\\\*/g, '.*').replace(/\\\?/g, '.') + '$';
      return new RegExp(rx);
    }
    return null; // treat as exact string
  }
  function matchesKeyWithPatterns(key, patterns, cfg) {
    for (const p of patterns) {
      const rx = patternToRegex(p, cfg);
      if (!rx) { if (key === p) return true; } else if (rx.test(key)) return true;
    }
    return false;
  }

  // ------------------ Bridge (iOS + simplified Android only) ------------------
  const __KNOT_MSG_Q__ = []; // queue for early posts
  let BRIDGE = null;
  let __KNOT_RETRY_TIMER__ = null;

  function selectBridge() {
    const cfg = getConfig();

    // iOS (hard-coded handler name)
    const ios = window.webkit?.messageHandlers?.postStorageMessage;
    if (ios && typeof ios.postMessage === 'function') {
      const needsString = !!cfg.stringifyIOS;
      return {
        kind: 'ios',
        post(payload) { ios.postMessage(needsString ? JSON.stringify(payload) : payload); }
      };
    }

    // ANDROID: exactly window.JSInterface.postStorageMessage(String)
    if (window.JSInterface && typeof window.JSInterface.postStorageMessage === 'function') {
      return {
        kind: 'android:JSInterface.postStorageMessage',
        post(payload) { window.JSInterface.postStorageMessage(JSON.stringify(payload)); }
      };
    }

    return null; // no bridge yet
  }

  function ensureBridge() {
    if (!BRIDGE) BRIDGE = selectBridge();
    return BRIDGE;
  }

  // Persistent retry loop to flush queued messages when Android bridge attaches late
  function startQueueRetryLoop() {
    if (__KNOT_RETRY_TIMER__) return;
    const cfg = getConfig();
    const maxMs = Math.max(10000, cfg.androidRetryMs | 0); // min 10s
    const interval = 100;
    let elapsed = 0;
    __KNOT_RETRY_TIMER__ = setInterval(() => {
      elapsed += interval;
      const b = ensureBridge();
      if (b) {
        clearInterval(__KNOT_RETRY_TIMER__);
        __KNOT_RETRY_TIMER__ = null;
        try { for (const m of __KNOT_MSG_Q__) b.post(m); } finally { __KNOT_MSG_Q__.length = 0; }
        return;
      }
      if (elapsed >= maxMs) {
        clearInterval(__KNOT_RETRY_TIMER__);
        __KNOT_RETRY_TIMER__ = null;
      }
    }, interval);
  }

  // Native handshake: call from Android when JS is injected
  // webView.evaluateJavascript("window.__knotBridgeReady && window.__knotBridgeReady()", null)
  window.__knotBridgeReady = function() {
    try {
      const b = ensureBridge();
      if (!b && window.JSInterface && typeof window.JSInterface.postStorageMessage === 'function') {
        BRIDGE = { kind: 'android:JSInterface.postStorageMessage', post(p) { window.JSInterface.postStorageMessage(JSON.stringify(p)); } };
      }
      if (BRIDGE && __KNOT_MSG_Q__.length) {
        for (const m of __KNOT_MSG_Q__) BRIDGE.post(m);
        __KNOT_MSG_Q__.length = 0;
      }
    } catch (e) {
      logBreadcrumb(`__knotBridgeReady flush failed: ${e.message}`, 'storage_error');
    }
  };

  function sendStorageMessage(payload) {
    try {
      const b = ensureBridge();
      if (!b) {
        __KNOT_MSG_Q__.push(payload);
        startQueueRetryLoop();          // keep retrying until bridge appears
        logBreadcrumb('Queued storage payload; bridge not ready', 'storage_info');
        return;
      }
      b.post(payload);
    } catch (e) {
      logBreadcrumb(`bridge post failed: ${e.message}`, 'storage_error');
    }
  }

  // Try to flush on useful lifecycle moments
  (function wireEarlyFlushes() {
    const tryFlush = () => { if (__KNOT_MSG_Q__.length) window.__knotBridgeReady(); };
    document.addEventListener('DOMContentLoaded', tryFlush, { once: true });
    window.addEventListener('load', tryFlush, { once: true });
    document.addEventListener('visibilitychange', () => {
      if (document.visibilityState === 'visible') tryFlush();
    });
  })();

  // ------------------ Storage capture & gating ------------------
  function collectStorage() {
    const collect = (storage, name) => {
      try {
        const out = {};
        for (let i = 0; i < storage.length; i++) {
          const k = storage.key(i);
          if (k !== null) out[k] = storage.getItem(k);
        }
        return out;
      } catch (e) {
        logBreadcrumb(`${name} collection failed: ${e.message}`, 'storage_error');
        return {};
      }
    };
    return { localStorage: collect(localStorage, 'localStorage'), sessionStorage: collect(sessionStorage, 'sessionStorage') };
  }
  function hasMeaningfulChange(obj) {
    const a = obj?.localStorage && Object.keys(obj.localStorage).length > 0;
    const b = obj?.sessionStorage && Object.keys(obj.sessionStorage).length > 0;
    return !!(a || b);
  }

  // ------------------ Matching (exact keys, glob/regex, dot-paths) ------------------
  function getRequiredProps(storageType /* 'localStorage' | 'sessionStorage' */) {
    const cfg = getConfig();
    return (storageType === 'localStorage' ? cfg.localStorageRequiredProps : cfg.sessionStorageRequiredProps) || [];
  }

  function shouldMonitorKey(storageType, key, preValue = null) {
    if (!key || typeof key !== 'string') return false;
    const cfg = getConfig();
    const required = getRequiredProps(storageType);
    if (!required.length) return false;

    const keyNamePatterns = required.filter((p) => !p.startsWith('.'));
    const dotPaths = required.filter((p) => p.startsWith('.')).map((p) => p.slice(1));

    // 1) key-name match (exact + optional glob/regex)
    if (keyNamePatterns.length && matchesKeyWithPatterns(key, keyNamePatterns, cfg)) return true;

    // 2) dot-path mode (value must be JSON with those paths)
    if (!dotPaths.length) return false;
    const valueStr = (preValue !== null && preValue !== undefined)
      ? preValue
      : (storageType === 'localStorage' ? localStorage.getItem(key) : sessionStorage.getItem(key));
    if (!valueStr) return false;

    const parsed = safeJSONParse(valueStr);
    if (!isObject(parsed)) return false;
    return dotPaths.some((p) => resolveDotPath(parsed, p).exists);
  }

  // ------------------ Messaging: delta + complete ------------------
  function sendStorageDelta(storageType /* 'localStorage' | 'sessionStorage' */, key, operation /* 'set'|'remove' */, preValue = null) {
    try {
      if (!shouldMonitorKey(storageType, key, preValue)) return;

      const currentValue = (preValue !== null && preValue !== undefined)
        ? preValue
        : (key ? (storageType === 'localStorage' ? localStorage.getItem(key) : sessionStorage.getItem(key)) : null);

      const payload = {
        type: 'storage_delta',
        change: {
          type: storageType,     // back-compat
          key,
          operation,             // 'set' | 'remove'
          storageType,           // explicit
          value: currentValue,   // raw string (or null for remove)
          timestamp: Date.now(),
        },
      };
      sendStorageMessage(payload);
    } catch (e) {
      logBreadcrumb(`sendStorageDelta failed: ${e.message}`, 'storage_error');
    }
  }

  function sendCompleteStorage(triggerType, key, operation) {
    try {
      const snapshot = collectStorage();
      if (!hasMeaningfulChange(snapshot)) return;
      const payload = {
        type: 'complete_storage',
        trigger: { type: triggerType || 'unknown', key: key || null, operation: operation || 'unknown' },
        localStorage: snapshot.localStorage,
        sessionStorage: snapshot.sessionStorage,
        timestamp: Date.now(),
      };
      sendStorageMessage(payload);
    } catch (e) {
      logBreadcrumb(`sendCompleteStorage failed: ${e.message}`, 'storage_error');
    }
  }

  // ------------------ Late-write tracking ------------------
  let __pollingActive = true;
  let __lateWriteTimer = null;

  // ------------------ Patch Storage.prototype ------------------
  const proto = window.Storage && window.Storage.prototype;
  if (!proto) { logBreadcrumb('Storage.prototype missing; aborting hook', 'storage_error'); return; }

  const _setItem = proto.setItem;
  const _removeItem = proto.removeItem;
  const _clear = proto.clear;

  function storageKind(self) {
    if (self === window.localStorage) return 'localStorage';
    if (self === window.sessionStorage) return 'sessionStorage';
    return undefined;
  }

  proto.setItem = function patchedSetItem(key, value) {
    const kind = storageKind(this);
    const result = _setItem.apply(this, arguments);
    if (kind) {
      sendStorageDelta(kind, key, 'set', null);
      if (getConfig().enableLateWriteCapture && !__pollingActive) {
        clearTimeout(__lateWriteTimer);
        __lateWriteTimer = setTimeout(function () {
          sendCompleteStorage('late_write', key, 'set');
        }, 500);
      }
    }
    return result;
  };

  proto.removeItem = function patchedRemoveItem(key) {
    const kind = storageKind(this);
    let pre = null;
    if (kind) pre = (kind === 'localStorage' ? localStorage.getItem(key) : sessionStorage.getItem(key));
    const result = _removeItem.apply(this, arguments);
    if (kind) {
      sendStorageDelta(kind, key, 'remove', pre);
      if (getConfig().enableLateWriteCapture && !__pollingActive) {
        clearTimeout(__lateWriteTimer);
        __lateWriteTimer = setTimeout(function () {
          sendCompleteStorage('late_write', key, 'remove');
        }, 500);
      }
    }
    return result;
  };

  proto.clear = function patchedClear() {
    const kind = storageKind(this);
    const result = _clear.apply(this, arguments);
    if (kind) {
      // Authoritative clear signal: native merges complete_storage payloads, so an empty
      // post-clear snapshot would leave stale keys cached. Emit a delta with operation
      // 'clear' (bypassing shouldMonitorKey) so native wipes the whole storage type.
      try {
        sendStorageMessage({
          type: 'storage_delta',
          change: {
            type: kind,
            key: null,
            operation: 'clear',
            storageType: kind,
            value: null,
            timestamp: Date.now(),
          },
        });
      } catch (e) {
        logBreadcrumb(`patchedClear delta failed: ${e.message}`, 'storage_error');
      }
      if (getConfig().enableLateWriteCapture && !__pollingActive) {
        clearTimeout(__lateWriteTimer);
        __lateWriteTimer = setTimeout(function () {
          sendCompleteStorage('late_write', null, 'clear');
        }, 500);
      }
    }
    return result;
  };

  // ------------------ Initial complete snapshot (queue if bridge not ready) ------------------
  (function sendInitialCompleteWhenReady() {
    setTimeout(() => {
      try {
        const snapshot = collectStorage();
        if (!hasMeaningfulChange(snapshot)) return;
        const payload = {
          type: 'complete_storage',
          trigger: { type: 'initial_load', key: null, operation: 'initial' },
          localStorage: snapshot.localStorage,
          sessionStorage: snapshot.sessionStorage,
          timestamp: Date.now(),
        };
        sendStorageMessage(payload);  // sends now or queues + retries until bridge appears
      } catch (e) {
        logBreadcrumb(`initial complete snapshot failed: ${e.message}`, 'storage_error');
      }
    }, 100);
  })();

  // ------------------ Periodic polling for async storage writes ------------------
  // Captures late writes (e.g., MSAL token exchange) that the setItem interceptor
  // may miss due to empty requiredProps or JS context timing issues.
  (function startStoragePolling() {
    if (!getConfig().enableLateWriteCapture) return;
    
    let lastHash = '';
    const intervalMs = 2000; // poll every 2 seconds
    const maxPolls = 15; // hard cap: 30 seconds total
    let pollCount = 0;

    function hashStorage(snap) {
      const pairs = [];
      var s = snap.sessionStorage || {};
      var l = snap.localStorage || {};
      for (var k in s) pairs.push('s:' + k + '=' + s[k]);
      for (var k in l) pairs.push('l:' + k + '=' + l[k]);
      return pairs.sort().join('|');
    }

    var timer = setInterval(function () {
      pollCount++;
      try {
        const snapshot = collectStorage();
        const currentHash = hashStorage(snapshot);

        if (currentHash !== lastHash && hasMeaningfulChange(snapshot)) {
          lastHash = currentHash;
          sendStorageMessage({
            type: 'complete_storage',
            trigger: { type: 'poll', key: null, operation: 'poll' },
            localStorage: snapshot.localStorage,
            sessionStorage: snapshot.sessionStorage,
            timestamp: Date.now(),
          });
        }
      } catch (e) {
        logBreadcrumb('poll snapshot failed: ' + e.message, 'storage_error');
      }

      if (pollCount >= maxPolls) {
        clearInterval(timer);
        __pollingActive = false;
      }
    }, intervalMs);
  })();

  // Optional manual resync (native can call)
  window.__knotStorageResync = function(storageType /* 'local' | 'session' | 'both' */) {
    const t = storageType || 'both';
    if (t === 'local' || t === 'both') sendCompleteStorage('manual_resync', null, 'local');
    if (t === 'session' || t === 'both') sendCompleteStorage('manual_resync', null, 'session');
  };
})();
