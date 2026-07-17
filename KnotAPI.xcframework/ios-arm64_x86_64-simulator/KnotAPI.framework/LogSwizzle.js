try {
  function parseMsg(msg) {
    let message = "";
    if (typeof msg === 'object') {
      try {
        message = JSON.stringify(msg);
      } catch (e) {
        message = "Can't parse object";
      }
    } else if (typeof msg === 'string') {
      message = msg;
    }
    return message;
  }

  (() => {
    var __log = console.log;
    console.log = (msg) => {
      const message = parseMsg(msg);
      window.webkit.messageHandlers.consoleLog?.postMessage({"msg": message});
      __log(message);
    };

    var __error = console.error;
    console.error = (msg) => {
      const message = parseMsg(msg);
      if (msg) {
        window.webkit.messageHandlers.consoleError?.postMessage({"msg": message});
        __error(message);
      }
    };
  })();
} catch (e) {
  window.webkit.messageHandlers.consoleError?.postMessage({"msg": "Can't catch logging"});
}
