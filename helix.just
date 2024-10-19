_default:
  @just --list

queries_target := "~/.config/helix/runtime/queries/tera/"
queries_src := justfile_directory() / "queries/"

init:
  mkdir -p ~/.config/helix/runtime/queries/tera/

sync: init
  cp {{ queries_src }}* {{ queries_target }}

clean:
  rm -rf {{ queries_target }}*

link: init clean
  ln -s {{ queries_src }}* {{ queries_target }}
