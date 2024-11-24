(
  (frontmatter_content) @yaml_frontmatter
    (#match? @yaml_frontmatter "whiskers:\\s*\\n(?:\\s{2,}\\S.*\\n)*\\s{2,}filename:\\s*\".+\\.css\"\\s*$")
  (content) @injection.content
  (#set! injection.language "css")
  (#set! injection.combined)
)
(
  (frontmatter_content) @yaml_frontmatter
    (#match? @yaml_frontmatter "whiskers:\\s*\\n(?:\\s{2,}\\S.*\\n)*\\s{2,}filename:\\s*\".+\\.html\"\\s*$")
  (content) @injection.content
  (#set! injection.language "html")
  (#set! injection.combined)
)
(
  (frontmatter_content) @yaml_frontmatter
    (#match? @yaml_frontmatter "whiskers:\\s*\\n(?:\\s{2,}\\S.*\\n)*\\s{2,}filename:\\s*\".+\\.json\"\\s*$")
  (content) @injection.content
  (#set! injection.language "json")
  (#set! injection.combined)
)
(
  (frontmatter_content) @yaml_frontmatter
    (#match? @yaml_frontmatter "whiskers:\\s*\\n(?:\\s{2,}\\S.*\\n)*\\s{2,}filename:\\s*\".+\\.yaml\"\\s*$")
  (content) @injection.content
  (#set! injection.language "yaml")
  (#set! injection.combined)
)
(
  (frontmatter_content) @yaml_frontmatter
    (#match? @yaml_frontmatter "whiskers:\\s*\\n(?:\\s{2,}\\S.*\\n)*\\s{2,}filename:\\s*\".+\\.toml\"\\s*$")
  (content) @injection.content
  (#set! injection.language "toml")
  (#set! injection.combined)
)
((frontmatter_content) @injection.content
  (#set! injection.language "yaml"))