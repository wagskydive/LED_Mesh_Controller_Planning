const sceneList = document.getElementById('scene-list') as HTMLUListElement;
const sceneName = document.getElementById('scene-name') as HTMLInputElement;
const sceneEffect = document.getElementById('scene-effect') as HTMLSelectElement;
const nodeList = document.getElementById('node-list') as HTMLUListElement;
const universe = document.getElementById('universe') as HTMLInputElement;
const startChannel = document.getElementById('start-channel') as HTMLInputElement;
const ledCount = document.getElementById('led-count') as HTMLInputElement;
const dmxUniverse = document.getElementById('dmx-universe') as HTMLInputElement;
const isRoot = document.getElementById('is-root') as HTMLInputElement;
const ssid = document.getElementById('ssid') as HTMLInputElement;
const password = document.getElementById('password') as HTMLInputElement;

interface Scene { id: number; name: string; effect: string; }
interface Settings {
  universe: number;
  start_channel: number;
  led_count: number;
  dmx_universe: number;
  is_root: boolean;
  ssid: string;
  password: string;
}

function loadSettings() {
  fetch('/settings').then(r => r.json()).then((s: Settings) => {
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
  const body: Settings = {
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
  fetch('/scenes').then(r => r.json()).then((data: Scene[]) => {
    sceneList.innerHTML = '';
    data.forEach(sc => {
      const li = document.createElement('li');
      li.textContent = sc.name;
      li.onclick = () => playScene(sc.id);
      sceneList.appendChild(li);
    });
  });
}

function saveScene() {
  fetch('/scenes').then(r => r.json()).then((data: Scene[]) => {
    const id = Date.now();
    data.push({ id, name: sceneName.value, effect: sceneEffect.value });
    return fetch('/scenes', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify(data)
    });
  }).then(loadScenes);
}

function playScene(id: number) {
  fetch('/play', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ id })
  });
}

function loadNodes() {
  fetch('/nodes').then(r => r.json()).then((data: string[]) => {
    nodeList.innerHTML = '';
    data.forEach(n => {
      const li = document.createElement('li');
      li.textContent = n;
      nodeList.appendChild(li);
    });
  });
}

document.getElementById('save-btn')?.addEventListener('click', saveScene);
document.getElementById('reload-btn')?.addEventListener('click', loadScenes);
document.getElementById('nodes-btn')?.addEventListener('click', loadNodes);
document.getElementById('save-settings-btn')?.addEventListener('click', saveSettings);

loadScenes();
loadSettings();
