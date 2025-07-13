# 🎟️ Ticket Backlog

## 🎟️ Ticket T0.1: Initialize Development Environment & Git Repository

**Milestone**: Project Bootstrap  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: Critical

### 🎯 Description
Set up the development environment so that the project can be managed, versioned, and extended automatically. Tasks include:

- Initialize a new Git repository
- Create a `.gitignore` file
- Create `/src`, `/data`, `/docs`, `/lib`
- Add basic `README.md`
- Create PlatformIO or Arduino project base

### ✅ Checklist
- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.1: NVS Settings Schema

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description
Create a settings manager using Preferences:
- universe, startChannel, ledCount, dmxUniverse, mode, isRoot
- Load on boot, update via API

### ✅ Checklist
- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.2: Wi-Fi Setup with Fallback AP Mode

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description
Implement dual-mode Wi-Fi setup:
- Connect to saved network
- Fallback to AP with captive portal
- Save SSID/pass using Preferences

### ✅ Checklist
- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T1.3: HTTP Server & API Bootstrap

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ✅ Completed
**Priority**: High

### 🎯 Description
Setup AsyncWebServer and REST API:
- Serve HTML UI
- GET/POST `/settings`
- Use SPIFFS + ArduinoJson

### ✅ Checklist
- [x] Started
- [x] Tests Written
- [x] Code Written
- [x] Tests Passed
- [x] Documentation Written

---

## 🎟️ Ticket T2.1: ESP-Mesh Init

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: 🚧 In Progress
**Priority**: High

### 🎯 Description
Set up the ESP-Mesh network layer so nodes can join a mesh.
Use the ESP-IDF mesh APIs. Prepare a MeshManager class with a `begin()` method.

### ✅ Checklist
- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written

---

## 🎟️ Ticket T2.2: Root Node Auto-Election

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: 🚧 In Progress
**Priority**: High

### 🎯 Description
Implement logic so that one node in the mesh becomes the root automatically.
Expose `is_root_node()` in `MeshManager`.

### ✅ Checklist
- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written

---

## 🎟️ Ticket T2.3: Mesh Messaging

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: 🚧 In Progress
**Priority**: Medium

### 🎯 Description
Provide broadcast messaging between nodes.
Add `send_message()` and `on_message()` handlers in `MeshManager`.

### ✅ Checklist
- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written

---

## 🎟️ Ticket T2.4: LED Feedback for Mesh State

**Milestone**: Mesh Networking Framework
**Created by**: system
**Status**: 🚧 In Progress
**Priority**: Low

### 🎯 Description
Use the onboard LED to indicate mesh status:
- Fast blink when searching
- Solid when connected as root
- Slow blink when connected as a node

### ✅ Checklist
- [ ] Started
- [ ] Tests Written
- [ ] Code Written
- [ ] Tests Passed
- [ ] Documentation Written
