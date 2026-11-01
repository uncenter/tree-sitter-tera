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
    # export to same subpath as on deployed github pages version
    {{ tree-sitter }} playground --export _site/tree-sitter-tera
    node playground/customize.js _site/tree-sitter-tera
    @echo "Playground: http://localhost:8000/tree-sitter-tera/"
    python3 -m http.server -d _site
