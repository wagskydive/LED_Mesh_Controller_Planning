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
**Status**: ☐ Started  
**Priority**: High

### 🎯 Description
Create a settings manager using Preferences:
- universe, startChannel, ledCount, dmxUniverse, mode, isRoot
- Load on boot, update via API

### ✅ Checklist
- [ ] Started  
- [ ] Tests Written  
- [ ] Code Written  
- [ ] Tests Passed  
- [ ] Documentation Written

---

## 🎟️ Ticket T1.2: Wi-Fi Setup with Fallback AP Mode

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ☐ Started  
**Priority**: High

### 🎯 Description
Implement dual-mode Wi-Fi setup:
- Connect to saved network
- Fallback to AP with captive portal
- Save SSID/pass using Preferences

### ✅ Checklist
- [ ] Started  
- [ ] Tests Written  
- [ ] Code Written  
- [ ] Tests Passed  
- [ ] Documentation Written

---

## 🎟️ Ticket T1.3: HTTP Server & API Bootstrap

**Milestone**: Core System Initialization  
**Created by**: system  
**Status**: ☐ Started  
**Priority**: High

### 🎯 Description
Setup AsyncWebServer and REST API:
- Serve HTML UI
- GET/POST `/settings`
- Use SPIFFS + ArduinoJson

### ✅ Checklist
- [ ] Started  
- [ ] Tests Written  
- [ ] Code Written  
- [ ] Tests Passed  
- [ ] Documentation Written
