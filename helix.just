_default:
  @just --list

queries_target := "~/.config/helix/runtime/queries/tera/"
queries_src := justfile_directory() / "helix-queries/"
original_queries_src := justfile_directory() / "queries/"

_init:
  mkdir -p {{ queries_target }}

build:
  #!/usr/bin/env bash
  mkdir -p {{ queries_src }}
  cp {{ original_queries_src }}* {{ queries_src }}
  for file in {{ queries_src }}/*; do
    tsqr "$file" -o "$file"
  done

sync: _init
  cp {{ queries_src }}* {{ queries_target }}

clean:
  rm -rf {{ queries_target }}*

link: _init clean
  ln -s {{ queries_src }}* {{ queries_target }}
