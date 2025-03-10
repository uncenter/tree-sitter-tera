# tree-sitter-tera

[Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar and syntax highlight queries for the [Tera](https://keats.github.io/tera/) templating language.

<!-- prettier-ignore -->
> [!TIP]
> _This repository provides support for Helix and Neovim. For Visual Studio Code support, see [uncenter/vscode-tera](https://github.com/uncenter/vscode-tera). For Zed support, see [uncenter/zed-tera](https://github.com/uncenter/zed-tera)._

[![Screenshot of highlighted sample Tera code in Helix with the tree-sitter-tera grammar installed](./assets/helix.png)](./assets/helix.png)

_Helix with tree-sitter-tera. Screenshot taken with the [catppuccin/helix](https://github.com/catppuccin/helix) theme._

[![Screenshot of highlighted sample Tera code in Neovim with the tree-sitter-tera grammar installed](./assets/neovim.png)](./assets/neovim.png)

_Neovim with tree-sitter-tera. Screenshot taken with the [catppuccin/nvim](https://github.com/catppuccin/nvim) theme._

## Usage

### Helix

> [!NOTE]
> As of 2025-02-02, tree-sitter-tera is included for Tera language support in Helix (unreleased).

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

### Neovim

#### nixvim

```nix
{
  pkgs,
  config,
  ...
}:
let
  tree-sitter-tera = pkgs.tree-sitter-grammars.tree-sitter-tera;
in
{
  config.programs.nixvim = {
    enable = true;

    plugins = {
      treesitter = {
        enable = true;

        grammarPackages = pkgs.vimPlugins.nvim-treesitter.passthru.allGrammars ++ [
          tree-sitter-tera
        ];
      };
    };

    extraConfigLua = # lua
      ''
        do
          vim.filetype.add({ extension = { tera = "tera" } })

          vim.api.nvim_create_autocmd("FileType", {
            pattern = "tera",
            callback = function(event)
              vim.bo[event.buf].commentstring = "{# %s #}"
            end,
          })

          require("nvim-treesitter.parsers").get_parser_configs().tera = {
            install_info = {
              url = "${tree-sitter-tera}",
              files = { "src/parser.c" },
            },
            filetype = "tera",
          }
        end
      '';

    extraPlugins = [
      tree-sitter-tera
    ];
  };
}
```

#### [nvim-treesitter](https://github.com/nvim-treesitter/nvim-treesitter)

##### Neovim stable:

```lua
vim.filetype.add({ extension = { tera = "tera" } })

vim.api.nvim_create_autocmd("FileType", {
	pattern = "tera",
	callback = function(event)
		vim.bo[event.buf].commentstring = "{# %s #}"
	end,
})
```

Then, run the following command:

```
:TSInstall tera
```

##### Neovim Nightly:

Run the following command:

```
:TSInstall tera
```

## License

[MIT](LICENSE)
