# 🏁 Sprint-to-Release Roadmap  
_LED Mesh Controller – v1.0_

> Goal: ship a feature-complete, stable build (firmware + WebUI) ready for field use in clubs / installations.

---

## 📅 Sprint 0 — Bootstrap & Repo Hygiene  (1–2 days)

| ✔︎ | Task ID | Description |
|----|---------|-------------|
| [ ] | T0.1   | Run `setup.sh`, commit initial repo scaffold |
| [ ] | T0.2   | Configure GitHub Actions / PlatformIO compile check |
| [ ] | T0.3   | Enforce `clang-format` / `prettier` hooks |

---

## 📅 Sprint 1 — Core System Green (4–5 days)

### Milestone 1.1 — Settings & Wi-Fi
- [ ] **T1.1** NVS settings schema complete  
- [ ] **T1.2** Wi-Fi STA/AP with captive portal  
- [ ] **T1.3** AsyncWebServer base (`/settings` GET/POST)

### Milestone 1.2 — Ticket Hygiene
- [ ] Seed unit tests for Settings, Wi-Fi  
- [ ] Update ticket checkboxes (Tests Written / Passed)

---

## 📅 Sprint 2 — Mesh & Sync (1 week)

### Milestone 2.1 — Mesh Reliability
- [ ] **T2.1** ESP-Mesh init + stable link  
- [ ] **T2.2** RSSI-based root election  
- [ ] **T2.3** JSON sync broadcast (`fx`, `color`, `bpm`)

### Milestone 2.2 — Node Status API
- [ ] `/status` endpoint returns node list & current root  
- [ ] WebSocket `/ws` push every 500 ms

---

## 📅 Sprint 3 — FX Engine & AutoFX (1 week)

### Milestone 3.1 — FX Library v1
- [ ] Static, Chase, Wipe, Bounce, ColorCycle, Pulse

### Milestone 3.2 — AutoFX & Complementary Colors
- [ ] Color-harmony generator (HSL → RGB)  
- [ ] `/api/auto` enable/disable with speed param

### Milestone 3.3 — Unit Tests
- [ ] Color conversion tests  
- [ ] FX renderer timing tests

---

## 📅 Sprint 4 — Art-Net & DMX (1 week)

### Milestone 4.1 — Art-Net Input
- [ ] UDP 6454 listener, universe filter  
- [ ] Map to LED buffer

### Milestone 4.2 — DMX Output
- [ ] MAX485 UART break/mark‐after-break  
- [ ] `/settings` toggle physical DMX

---

## 📅 Sprint 5 — Pro Console UX (1–1.5 weeks)

### Milestone 5.1 — UI Foundation
- [ ] Refactor JS → `app.js` (ES modules or Vite)  
- [ ] WebSocket live updates

### Milestone 5.2 — Color Wheel & FX Pads
- [ ] Integrate `iro.js` wheel  
- [ ] Animated FX preview pads

### Milestone 5.3 — Node Dashboard
- [ ] Node cards with color swatch, FX icon, RSSI, root badge  
- [ ] Manual “Promote to Root” button

### Milestone 5.4 — Scene Manager v1
- [ ] Record, rename, save to SPIFFS (`scenes.json`)  
- [ ] Drawer UI & click-to-play

---

## 📅 Sprint 6 — QA / Field Testing (4-5 days)

- [ ] Full mesh stress test (≥ 10 nodes)  
- [ ] Latency / FPS measurement  
- [ ] Memory usage & brown-out test  
- [ ] Docs: Quick Start, Wiring, UI guide

---

## 📅 Sprint 7 — Release Prep (2 days)

- [ ] Bump version to **v1.0.0**  
- [ ] Tag & GitHub Release zip  
- [ ] Changelog `CHANGELOG.md`  
- [ ] Final README badges & screenshots

---

## 🚦 Completion Criteria

- All tickets’ checklists show ✅ Tests Passed & Documentation Written  
- Demo video recorded in club environment  
- At least one third-party tester reproduces setup from README successfully

---

## 🙌 Post-v1.0 Ideas (Backlog)

- Mic / Audio Reactive FX  
- Camera Color-Sample strobe  
- OTA firmware updater  
- Native iOS / Android wrapper  
