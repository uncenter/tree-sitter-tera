# tree-sitter-tera

[Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar and syntax highlight queries for the [Tera](https://keats.github.io/tera/) templating language.

## Usage

### Helix

> [!NOTE]
> Refer to https://docs.helix-editor.com/guides/adding_languages.html for more details if needed.

1. Add the sample language and grammar configuration for Tera from [`languages.toml`](./languages.toml) to your own [`languages.toml` configuration file](https://docs.helix-editor.com/configuration.html).
2. Run `hx --grammar fetch` to fetch the grammar from this repository, and then `hx --grammar build` to build the grammars.
3. Run `just helix sync` or `just helix link` to copy or symlink the [queries](./queries) to Helix's runtime directory, as unfortunately [queries are not used from the grammar repository by default](https://github.com/helix-editor/helix/discussions/11379#discussioncomment-10194806).

## License

[MIT](LICENSE)
