_default:
  @just --list

sync:
  mkdir -p ~/.config/helix/runtime/queries/tera/
  cp queries/* ~/.config/helix/runtime/queries/tera/
