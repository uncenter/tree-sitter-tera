package tree_sitter_tera_test

import (
	"testing"

	tree_sitter "github.com/tree-sitter/go-tree-sitter"
	tree_sitter_tera "github.com/uncenter/tree-sitter-tera/bindings/go"
)

func TestCanLoadGrammar(t *testing.T) {
	language := tree_sitter.NewLanguage(tree_sitter_tera.Language())
	if language == nil {
		t.Errorf("Error loading Tera grammar")
	}
}
