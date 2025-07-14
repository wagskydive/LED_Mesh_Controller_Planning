#!/bin/sh
HOOK_DIR="$(git rev-parse --git-dir)/hooks"
mkdir -p "$HOOK_DIR"
cp scripts/hooks/pre-commit "$HOOK_DIR/pre-commit"
chmod +x "$HOOK_DIR/pre-commit"
echo "Hooks installed to $HOOK_DIR"
