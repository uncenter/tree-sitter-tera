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

As of v<next-released-version>, tree-sitter-tera is included by default for Tera language support in Helix!

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

#### Lazy.nvim

Extend your nvim-treesitter plugin with this Tera plugin.

```lua
{
    "nvim-treesitter/nvim-treesitter",
    config = function()
        -- setup treesitter with config
    end,
    dependencies = {
        ...
        { "uncenter/tree-sitter-tera", build = ":TSUpdate tera" },
        ...
    },
    build = ":TSUpdate",
},
```

#### Manual

```lua
local parser_config = require("nvim-treesitter.parsers").get_parser_configs()

parser_config.tera = {
  install_info = {
    url = "https://github.com/uncenter/tree-sitter-tera",
    files = { "src/parser.c" },
    branch = "main",
  },
  filetype = "tera",
}
```

Run `:TSInstall tera` in Neovim to install the above parser.

## License

[MIT](LICENSE)
