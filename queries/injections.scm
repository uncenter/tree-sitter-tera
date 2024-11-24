((frontmatter_content) @injection.content
  (#set! injection.language "yaml"))
(
  (frontmatter_content) @yaml_frontmatter
    (#match? @yaml_frontmatter "whiskers:\\s*\\n(?:\\s{2,}\\S.*\\n)*\\s{2,}filename:\\s*\".+\\.toml\"\\s*$")
  (content) @injection.content
  (#set! injection.language "toml")
  (#set! injection.combined)
)
