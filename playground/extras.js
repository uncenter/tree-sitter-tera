// Loaded before the stock playground.js, which restores state from localStorage on start.
(() => {
	const DEFAULTS = window.PLAYGROUND_DEFAULTS;

	function exampleState() {
		return {
			code: DEFAULTS.code,
			query: DEFAULTS.query,
			queryEnabled: true,
			anonymousNodes: false,
		};
	}

	function writeState({ code, query, queryEnabled, anonymousNodes }) {
		localStorage.setItem('language', 'parser');
		localStorage.setItem('sourceCode', code);
		localStorage.setItem('query', query);
		localStorage.setItem('queryEnabled', String(queryEnabled));
		localStorage.setItem('anonymousNodes', String(anonymousNodes));
	}

	function readSharedState() {
		const hash = location.hash.slice(1);
		if (!hash) return null;
		const json = LZString.decompressFromEncodedURIComponent(hash);
		if (!json) return null;
		return { ...exampleState(), ...JSON.parse(json) };
	}

	try {
		const shared = readSharedState();
		if (shared) {
			writeState(shared);
			// Drop the hash so later reloads keep edits instead of shared state.
			history.replaceState(null, '', location.pathname + location.search);
		} else if (localStorage.getItem('sourceCode') == null) {
			writeState(exampleState());
		}
	} catch (error) {
		console.error('Failed to load playground state', error);
	}

	// playground.js only saves state after a debounce, so read the editor directly.
	function currentState() {
		const editor = (id) =>
			document.querySelector(`#${id} .CodeMirror`).CodeMirror;
		return {
			code: editor('code-container').getValue(),
			query: editor('query-container').getValue(),
			queryEnabled: document.getElementById('query-checkbox').checked,
			anonymousNodes: document.getElementById('anonymous-nodes-checkbox')
				.checked,
		};
	}

	function addButton(label, onClick) {
		const item = document.createElement('div');
		item.className = 'header-item';
		const button = document.createElement('button');
		button.type = 'button';
		button.className = 'theme-toggle';
		button.style.font = 'inherit';
		button.textContent = label;
		button.addEventListener('click', () => onClick(button));
		item.append(button);
		document.getElementById('theme-toggle').closest('.header-item').before(item);
	}

	addButton('share', async (button) => {
		const state = currentState();
		// Shared links fall back to the default query, so keep URLs short.
		if (state.query === DEFAULTS.query) delete state.query;
		const hash = LZString.compressToEncodedURIComponent(JSON.stringify(state));
		const url = `${location.origin}${location.pathname}#${hash}`;
		await navigator.clipboard.writeText(url);
		button.textContent = 'link copied!';
		setTimeout(() => (button.textContent = 'share'), 2000);
	});

	addButton('reset', () => {
		writeState(exampleState());
		location.reload();
	});
})();
