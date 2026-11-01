// Customizes the playground exported by `tree-sitter playground --export`:
// embeds the default example and highlight queries, loads additional functionality from extras.js before playground.js.
//
// Usage: node playground/customize.js <export-dir>
import { copyFileSync, readFileSync, writeFileSync } from 'node:fs';
import { join } from 'node:path';

const EXAMPLE = 'examples/foo.html.tera';
const QUERY = 'queries/highlights.scm';
const LZ_STRING = {
	src: 'https://cdnjs.cloudflare.com/ajax/libs/lz-string/1.5.0/lz-string.min.js',
	integrity:
		'sha512-qtX0GLM3qX8rxJN1gyDfcnMFFrKvixfoEOwbBib9VafR5vbChV5LeE5wSI/x+IlCkTY5ZFddFDCCfaVJJNnuKQ==',
};

const site = process.argv[2];
if (!site) {
	console.error('Usage: node playground/customize.js <export-dir>');
	process.exit(1);
}

const root = join(import.meta.dirname, '..');
const defaults = {
	code: readFileSync(join(root, EXAMPLE), 'utf8'),
	query: readFileSync(join(root, QUERY), 'utf8'),
};
writeFileSync(
	join(site, 'defaults.js'),
	`window.PLAYGROUND_DEFAULTS = ${JSON.stringify(defaults)};\n`,
);
copyFileSync(join(import.meta.dirname, 'extras.js'), join(site, 'extras.js'));

const indexPath = join(site, 'index.html');
let html = readFileSync(indexPath, 'utf8');
const anchor = '<script type="module" src="playground.js"></script>';
// Grammar is loaded at `${LANGUAGE_BASE_URL}/tree-sitter-parser.wasm`.
// By default is the root path, which breaks when served from a subpath (GitHub Pages).
const baseUrl = '<script>LANGUAGE_BASE_URL = "";</script>';
for (const expected of [anchor, baseUrl]) {
	if (!html.includes(expected)) {
		throw new Error(
			`Couldn't find ${expected} in ${indexPath}; the exported playground may have changed.`,
		);
	}
}
html = html.replace(baseUrl, '<script>LANGUAGE_BASE_URL = ".";</script>');
const scripts = [
	`<script src="${LZ_STRING.src}" integrity="${LZ_STRING.integrity}" crossorigin="anonymous" referrerpolicy="no-referrer"></script>`,
	'<script src="defaults.js"></script>',
	'<script src="extras.js"></script>',
];
writeFileSync(
	indexPath,
	html.replace(anchor, [...scripts, anchor].join('\n    ')),
);
