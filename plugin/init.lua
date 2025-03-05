vim.filetype.add({ extension = { tera = "tera" } })

vim.api.nvim_create_autocmd("FileType", {
	pattern = "tera",
	callback = function(event)
		vim.bo[event.buf].commentstring = "{# %s #}"
	end,
})

require("nvim-treesitter.parsers").get_parser_configs().tera = {
	install_info = {
		url = "https://github.com/uncenter/tree-sitter-tera",
		files = { "src/parser.c", "src/scanner.c" },
		branch = "main",
	},
	filetype = "tera",
}
