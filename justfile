_default:
  @just --summary

play:
  tree-sitter generate
  tree-sitter build --wasm
  tree-sitter playground

build:
  tree-sitter generate

test:
  tree-sitter test
