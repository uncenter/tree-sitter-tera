_default:
  @just --list helix

queries_target := "~/.config/helix/runtime/queries/tera/"
queries_src := justfile_directory() / "helix-queries/"

_init:
  mkdir -p {{ queries_target }}

sync: _init
  cp {{ queries_src }}* {{ queries_target }}

clean:
  rm -rf {{ queries_target }}*

link: _init clean
  ln -s {{ queries_src }}* {{ queries_target }}
