function adjustViewPort() {
    try {
        var meta = document.createElement('meta');
        meta.setAttribute('name', 'viewport');
        meta.setAttribute('content', 'width=device-width, initial-scale=1, maximum-scale=1, viewport-fit=cover');
        const head = document.querySelector('head');
        head.appendChild(meta);

    } catch(e) {
        console.log(e)
    }
};
adjustViewPort()
