var _a, _b, _c, _d;
var sceneList = document.getElementById('scene-list');
var sceneName = document.getElementById('scene-name');
var sceneEffect = document.getElementById('scene-effect');
var nodeList = document.getElementById('node-list');
var universe = document.getElementById('universe');
var startChannel = document.getElementById('start-channel');
var ledCount = document.getElementById('led-count');
var dmxUniverse = document.getElementById('dmx-universe');
var isRoot = document.getElementById('is-root');
var ssid = document.getElementById('ssid');
var password = document.getElementById('password');
function loadSettings() {
    fetch('/settings').then(function (r) { return r.json(); }).then(function (s) {
        universe.value = String(s.universe);
        startChannel.value = String(s.start_channel);
        ledCount.value = String(s.led_count);
        dmxUniverse.value = String(s.dmx_universe);
        isRoot.checked = s.is_root;
        ssid.value = s.ssid;
        password.value = s.password;
    });
}
function saveSettings() {
    var body = {
        universe: parseInt(universe.value, 10),
        start_channel: parseInt(startChannel.value, 10),
        led_count: parseInt(ledCount.value, 10),
        dmx_universe: parseInt(dmxUniverse.value, 10),
        is_root: isRoot.checked,
        ssid: ssid.value,
        password: password.value
    };
    fetch('/settings', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(body)
    }).then(loadSettings);
}
function loadScenes() {
    fetch('/scenes').then(function (r) { return r.json(); }).then(function (data) {
        sceneList.innerHTML = '';
        data.forEach(function (sc) {
            var li = document.createElement('li');
            li.textContent = sc.name;
            li.onclick = function () { return playScene(sc.id); };
            sceneList.appendChild(li);
        });
    });
}
function saveScene() {
    fetch('/scenes').then(function (r) { return r.json(); }).then(function (data) {
        var id = Date.now();
        data.push({ id: id, name: sceneName.value, effect: sceneEffect.value });
        return fetch('/scenes', {
            method: 'POST',
            headers: { 'Content-Type': 'application/json' },
            body: JSON.stringify(data)
        });
    }).then(loadScenes);
}
function playScene(id) {
    fetch('/play', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify({ id: id })
    });
}
function loadNodes() {
    fetch('/nodes').then(function (r) { return r.json(); }).then(function (data) {
        nodeList.innerHTML = '';
        data.forEach(function (n) {
            var li = document.createElement('li');
            li.textContent = n;
            nodeList.appendChild(li);
        });
    });
}
(_a = document.getElementById('save-btn')) === null || _a === void 0 ? void 0 : _a.addEventListener('click', saveScene);
(_b = document.getElementById('reload-btn')) === null || _b === void 0 ? void 0 : _b.addEventListener('click', loadScenes);
(_c = document.getElementById('nodes-btn')) === null || _c === void 0 ? void 0 : _c.addEventListener('click', loadNodes);
(_d = document.getElementById('save-settings-btn')) === null || _d === void 0 ? void 0 : _d.addEventListener('click', saveSettings);
loadScenes();
loadSettings();
