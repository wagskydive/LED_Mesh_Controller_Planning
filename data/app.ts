const sceneList = document.getElementById('scene-list') as HTMLUListElement;
const sceneName = document.getElementById('scene-name') as HTMLInputElement;
const sceneEffect = document.getElementById(
  'scene-effect'
) as HTMLSelectElement;
const nodeList = document.getElementById('node-list') as HTMLUListElement;
const rootStatus = document.getElementById(
  'root-status'
) as HTMLParagraphElement;
const universe = document.getElementById('universe') as HTMLInputElement;
const startChannel = document.getElementById(
  'start-channel'
) as HTMLInputElement;
const ledCount = document.getElementById('led-count') as HTMLInputElement;
const dmxUniverse = document.getElementById('dmx-universe') as HTMLInputElement;
const enableDmx = document.getElementById('enable-dmx') as HTMLInputElement;
const isRoot = document.getElementById('is-root') as HTMLInputElement;
const extendNetwork = document.getElementById(
  'extend-network'
) as HTMLInputElement;
const wifiDiv = document.getElementById('wifi-credentials') as HTMLDivElement;
const ssid = document.getElementById('ssid') as HTMLInputElement;
const password = document.getElementById('password') as HTMLInputElement;
const restartBtn = document.getElementById('restart-btn') as HTMLButtonElement;

interface Scene {
  id: number;
  name: string;
  effect: string;
}
interface Settings {
  universe: number;
  start_channel: number;
  led_count: number;
  dmx_universe: number;
  enable_dmx: boolean;
  is_root: boolean;
  extend_network: boolean;
  ssid: string;
  password: string;
}

function loadSettings() {
  fetch('/settings')
    .then((r) => r.json())
    .then((s: Settings) => {
      universe.value = String(s.universe);
      startChannel.value = String(s.start_channel);
      ledCount.value = String(s.led_count);
      dmxUniverse.value = String(s.dmx_universe);
      enableDmx.checked = s.enable_dmx;
      isRoot.checked = s.is_root;
      extendNetwork.checked = s.extend_network;
      ssid.value = s.ssid;
      password.value = s.password;
      toggleWifi();
    });
}

function saveSettings() {
  const body: Settings = {
    universe: parseInt(universe.value, 10),
    start_channel: parseInt(startChannel.value, 10),
    led_count: parseInt(ledCount.value, 10),
    dmx_universe: parseInt(dmxUniverse.value, 10),
    enable_dmx: enableDmx.checked,
    is_root: isRoot.checked,
    extend_network: extendNetwork.checked,
    ssid: ssid.value,
    password: password.value,
  };
  fetch('/settings', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify(body),
  }).then(loadSettings);
}

function loadScenes() {
  fetch('/scenes')
    .then((r) => r.json())
    .then((data: Scene[]) => {
      sceneList.innerHTML = '';
      data.forEach((sc) => {
        const li = document.createElement('li');
        const span = document.createElement('span');
        span.textContent = sc.name;
        span.onclick = () => playScene(sc.id);
        const btn = document.createElement('button');
        btn.textContent = 'Rename';
        btn.onclick = () => renameScene(sc.id);
        li.appendChild(span);
        li.appendChild(btn);
        sceneList.appendChild(li);
      });
    });
}

function saveScene() {
  fetch('/scenes')
    .then((r) => r.json())
    .then((data: Scene[]) => {
      const id = Date.now();
      data.push({ id, name: sceneName.value, effect: sceneEffect.value });
      return fetch('/scenes', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(data),
      });
    })
    .then(loadScenes);
}

function renameScene(id: number) {
  const newName = prompt('New scene name?');
  if (!newName) {
    return;
  }
  fetch('/scenes')
    .then((r) => r.json())
    .then((data: Scene[]) => {
      const scene = data.find((s) => s.id === id);
      if (scene) {
        scene.name = newName;
      }
      return fetch('/scenes', {
        method: 'POST',
        headers: { 'Content-Type': 'application/json' },
        body: JSON.stringify(data),
      });
    })
    .then(loadScenes);
}

function playScene(id: number) {
  fetch('/play', {
    method: 'POST',
    headers: { 'Content-Type': 'application/json' },
    body: JSON.stringify({ id }),
  });
}

function toggleWifi() {
  wifiDiv.style.display = extendNetwork.checked ? 'block' : 'none';
}

function loadNodes() {
  fetch('/status')
    .then((r) => r.json())
    .then((data: { nodes: string[]; is_root: boolean }) => {
      nodeList.innerHTML = '';
      rootStatus.textContent = data.is_root ? 'Root node' : 'Mesh node';
      data.nodes.forEach((n) => {
        const li = document.createElement('li');
        li.textContent = n;
        nodeList.appendChild(li);
      });
    });
}

document.getElementById('save-btn')?.addEventListener('click', saveScene);
document.getElementById('reload-btn')?.addEventListener('click', loadScenes);
document
  .getElementById('save-settings-btn')
  ?.addEventListener('click', saveSettings);
extendNetwork.addEventListener('change', toggleWifi);
restartBtn.addEventListener('click', () => {
  saveSettings();
  fetch('/restart', { method: 'POST' });
});

let ws: WebSocket | null = null;

function connectWebSocket() {
  ws = new WebSocket(`ws://${location.host}/ws`);
  ws.onmessage = (ev) => {
    const data = JSON.parse(ev.data) as { nodes: string[]; is_root: boolean };
    nodeList.innerHTML = '';
    rootStatus.textContent = data.is_root ? 'Root node' : 'Mesh node';
    data.nodes.forEach((n) => {
      const li = document.createElement('li');
      li.textContent = n;
      nodeList.appendChild(li);
    });
  };
  ws.onclose = () => {
    setTimeout(connectWebSocket, 1000);
  };
}

toggleWifi();

loadScenes();
loadSettings();
connectWebSocket();
