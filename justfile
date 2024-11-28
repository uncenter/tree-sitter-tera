mod helix

_default:
  @just --list-submodules

play:
  tree-sitter generate
  tree-sitter build --wasm
  tree-sitter playground

build:
  tree-sitter generate

test:
  tree-sitter test
