# tree-sitter-tera

[Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar and syntax highlight queries for the [Tera](https://keats.github.io/tera/) templating language.

This grammar supports syntax from both Tera v1 and Tera v2, including recent features like components, maps, list comprehensions, and slicing. Tera v1-only syntax, such as macros and imports, is still parsed.

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

As of Helix v25.07, Tera language support is included out of the box.

## License

[MIT](LICENSE)
