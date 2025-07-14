# Release Procedure

1. Run `scripts/build_image.sh` to generate firmware and SPIFFS images.
2. Update `CHANGELOG.md` and bump the version in `README.md` if needed.
3. Tag the commit with the version, e.g. `git tag v1.0.0`.
4. Push tags and create a GitHub Release attaching the binaries from `images/`.
