# tree-sitter-tera

[Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar and syntax highlight queries for the [Tera](https://keats.github.io/tera/) templating language.

> [!TIP]
> See also Tera extensions for other editors:
> - Visual Studio Code: [uncenter/vscode-tera](https://github.com/uncenter/vscode-tera)
> - Zed: [uncenter/zed-tera](https://github.com/uncenter/zed-tera)
> - Sublime Text: [MuntasirSZN/sublime-tera](https://github.com/MuntasirSZN/sublime-tera)

## Usage

### Neovim

> [!IMPORTANT]
> Requires Neovim v0.11 or later.

Install the grammar by running the following command inside Neovim:

```
:TSInstall tera
```

### Helix

> [!NOTE]
> As of 2025-02-02 (unreleased), tree-sitter-tera is included for Tera language support in Helix.

1. Add the following language and grammar configuration to your own [`languages.toml` configuration file](https://docs.helix-editor.com/configuration.html):

```toml
[[grammar]]
name = "tera"

[grammar.source]
git = "https://github.com/uncenter/tree-sitter-tera"
rev = "main"

[[language]]
file-types = ["tera"]
grammar = "tera"
injection-regex = "tera"
name = "tera"
scope = "source.tera"
block-comment-tokens = [
  { start = "{#", end = "#}" },
  { start = "{#-", end = "-#}" },
  { start = "{#", end = "-#}" },
  { start = "{#-", end = "#}" },
]

[language.auto-pairs]
"\"" = "\""
"'" = "'"
"`" = "`"
"(" = ")"
"[" = "]"
"{" = "}"
"%" = "%"
```

2. Run `hx --grammar fetch` to fetch the grammar from this repository, and then `hx --grammar build` to build the grammars.
3. Run `just helix sync` or `just helix link` to copy or symlink the [Helix-specific queries](./helix-queries) to Helix's runtime directory, as unfortunately [queries are not used from the grammar repository by default](https://github.com/helix-editor/helix/discussions/11379#discussioncomment-10194806).

> [!IMPORTANT]
> Helix [uses the reverse query precedence ordering](https://github.com/helix-editor/helix/issues/9436), meaning that the _first_ matching highlight query is used rather than last; this is the opposite behavior of Neovim and Zed, both of which use the _last_ matching highlight query - think of it like CSS, where queries gain precedence by being located further down. Helix does seemingly plan to change this soon, but for now this repository has a separate folder for Helix-converted queries (built with `just helix build`, using [tree-sitter-query-reverser](https://github.com/uncenter/tree-sitter-query-reverser).

## License

[MIT](LICENSE)
