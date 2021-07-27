# [VEX tutorial](https://jtomori.github.io/vex_tutorial/)

You are seeing `website` branch, see `master` for markdown version of the tutorial.

The current workflow is to sync changes between markdown version in `master` and website version in `website` branches by hand. While not ideal, simple enough to do. The workflow goes like this:

1. Copy contents from `README.md` in `master` to `index.html` in `website` or vice versa - depending on what is newer.
2. There are 3 changes to do after each sync:

	2.1. Change title from `# VEX tutorial` to `**VEX tutorial**`

	2.2. Remove `# Topics` section in `index.html`

	2.3. Preserve 1st and last line in `index.html`