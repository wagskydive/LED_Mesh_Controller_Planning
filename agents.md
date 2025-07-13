
# 🤖 agents.md — AI Agent Instructions

This file defines the behavior, rules, and coding standards for any AI or automation tools contributing to this project.

## 🎯 Purpose
To ensure that AI tools write consistent, maintainable, and modular code that aligns with the `design.md`, `planning.md`, and `tickets.md`.

## 📘 Design Reference
- Always read `design.md` for overall goals and context
- Refer to `planning.md` for milestones and high-level tasks
- Create or update `tickets.md` for execution tasks

## 🔁 Task Behavior

- If no active ticket exists for the next milestone task, create one.
- If a ticket is too complex, break it down into sub-tickets (e.g. T3.2a, T3.2b).
- Always use the checklist format on tickets:
  - [ ] Started
  - [ ] Tests Written
  - [ ] Code Written
  - [ ] Tests Passed
  - [ ] Documentation Written

## ✨ Coding Standards

### ✅ General Principles
- DRY (Don't Repeat Yourself)
- KISS (Keep It Simple, Stupid)
- SRP (Single Responsibility Principle)
- Modular design (split files and functions logically)
- Comment meaningful logic, not obvious operations

### 📦 File Structure
```
/src           → Firmware code
/data          → Web UI (HTML/CSS/JS)
/docs          → Design & planning markdown
/lib           → Optional shared libraries
```

### 🧠 Language Conventions

#### C++ (Arduino)
- Use CamelCase for class names: `MeshManager`
- Use snake_case for functions and variables: `load_settings()`, `led_count`
- Constants: `const int MAX_UNIVERSE = 512;`
- Keep functions under ~50 lines

#### JavaScript (Frontend)
- camelCase for variables and functions: `updateScenePad()`
- PascalCase for classes: `SceneManager`
- Use ES6 syntax (let, const, arrow functions)

#### HTML/CSS
- kebab-case for CSS classes: `.fx-button`, `.scene-grid`
- Structure files by section (console, sidebar, overlays)

#### JSON
- snake_case keys: `{ "start_channel": 1 }`
- No comments (JSON spec)

## 📐 Version Control

- Use Git
- Commit messages should be meaningful: `Add WiFi AP fallback`, `Implement scene loader`
- Keep branches focused: one feature per branch
