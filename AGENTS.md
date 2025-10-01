# Repository Guidelines

## Project Structure & Module Organization
This CLI is centered around `src/`, where each module owns a slice of the command pipeline: `main.c` wires signals and the REPL, `parser.c` tokenizes input, `cmd.c` maps commands, and `ledger.c` handles persistence. Shared types live in `include/grind.h`. Utility routines are vendored in `libft/` and build into `libft.a`. Runtime data such as `ledger.tsv`, `quests.tsv`, and reward definitions are stored under `data/`; treat them as seed fixtures when developing.

## Build, Test, and Development Commands
Run `make` from the repo root to compile `grind`; it will also refresh the `libft` static library as needed. Use `make clean` to drop object files, `make fclean` to remove the binary, and `make re` for a full rebuild. Launch the CLI with `./grind` and optionally pass a TSV ledger path if you add that CLI support.

## Coding Style & Naming Conventions
We target C99 with tabs for indentation and brace-on-new-line formatting (see `src/handle_task.c` for reference). Prefer descriptive snake_case for functions and structs, and keep public declarations in `include/grind.h`. Reuse helpers from `libft` rather than rolling new utilities. When adding modules, mirror the existing pattern: place implementation in `src/feature.c`, declare interfaces in the header, and update `SRCS` inside the `Makefile`.

## Testing Guidelines
There is no automated harness yet, so exercise features manually. After any change, rebuild and run `./grind`, then verify typical flows: `ls quests`, `log quests 5`, `add quest "daily review"`, and `recap yield`. Keep a copy of the TSV fixtures before mutating them and document new columns. If you add regression coverage, colocate scripts under `task/` and reference them in this guide.

## Commit & Pull Request Guidelines
Recent history favors short, imperative messages such as `add parser guard` or `implement cmd handler`. Follow that pattern and scope each commit to one logical change. PRs should summarize behavior, link any relevant issue, and include CLI transcripts or screenshots that prove the change. Note data migrations explicitly and flag any manual steps reviewers must perform.
