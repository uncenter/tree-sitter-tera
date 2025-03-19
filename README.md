# tree-sitter-tera

[Tree-sitter](https://tree-sitter.github.io/tree-sitter/) grammar and syntax highlight queries for the [Tera](https://keats.github.io/tera/) templating language.

> [!TIP]
> For Visual Studio Code support, see [uncenter/vscode-tera](https://github.com/uncenter/vscode-tera). For Zed support, see [uncenter/zed-tera](https://github.com/uncenter/zed-tera).

## Usage

### Neovim

1. Add the following Lua code to your Neovim configuration (e.g. `init.lua` file or similar) to set up the Tera filetype.

> [!NOTE]
> This step is not required for users of the nightly Neovim distributions, as the Tera filetype has already been upstreamed ([vim/vim#16806](https://github.com/vim/vim/pull/16806), [neovim/neovim#32760](https://github.com/neovim/neovim/pull/32760)).

```lua
vim.filetype.add({ extension = { tera = "tera" } })

vim.api.nvim_create_autocmd("FileType", {
	pattern = "tera",
	callback = function(event)
		vim.bo[event.buf].commentstring = "{# %s #}"
	end,
})
```

2. Install the grammar by running the following command inside Neovim:

```
:TSInstall tera
```

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

### Helix

As of Helix v<next-released-version>, Tera language support is included out of the box.

## License

[MIT](LICENSE)
