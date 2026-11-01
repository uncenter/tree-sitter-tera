# Pinned tree-sitter from package.json.
tree-sitter := "pnpm exec tree-sitter"

_default:
    @just --summary

build:
    {{ tree-sitter }} generate

test:
    {{ tree-sitter }} test

playground: build
    {{ tree-sitter }} build --wasm
    {{ tree-sitter }} playground

site: build
    {{ tree-sitter }} build --wasm
    rm -rf _site
    {{ tree-sitter }} playground --export _site
    node playground/customize.js _site
    python3 -m http.server -d _site
