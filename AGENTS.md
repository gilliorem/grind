# Repository Guidelines

## Project Structure & Module Organization
Core sources sit under `src/`: `main.c` bootstraps the REPL, `parser.c` tokenizes input, `cmd.c` dispatches work, and `ledger.c` touches TSV storage. Shared types live in `include/grind.h`. `libft/` provides reusable C helpers compiled as `libft.a`. Runtime fixtures (`ledger.tsv`, `quests.tsv`, `rewards.tsv`) live in `data/`; copy them before experimenting to restore state quickly.

## Build, Test, and Development Commands
Run `make` to compile the CLI and refresh `libft.a`. Use `make clean` for objects, `make fclean` to drop the binary, and `make re` for a clean rebuild. Launch from the repo root with `./grind`.

## Coding Style & Naming Conventions
Target C99, tabs for indentation, and brace-on-new-line formatting (see `src/handle_task.c`). Functions, structs, and files use snake_case. Public declarations belong in `include/grind.h`. New features add `src/feature.c`, update `SRCS` in the `Makefile`, and lean on `libft` helpers over custom rewrites.

## Testing Guidelines
We rely on manual tests. After edits, rebuild and walk the main flows: `ls quests`, `log quests 5`, `add quest "daily review"`, `recap yield`. Snapshot TSV files before mutating them and document schema tweaks alongside the code.

## Commit & Pull Request Guidelines
Commits stay short, imperative, and scoped (e.g., `add parser guard`, `implement cmd handler`). PRs describe the behavior change, link issues, and add CLI transcripts or screenshots when output shifts. Note data migrations or reviewer steps.

## Architecture & Command Implementation
Centralize command metadata so names, contexts, and arguments remain aligned. Define a table in `cmd.c`:
```c
typedef struct {
    const char      *name;
    context_type     context;
    arg_type         arg;
    int            (*handler)(const t_request *);
} t_command_spec;
```
Add entries like `{ "log", CTX_QUESTS, ARG_INT, &handle_log }` and keep one authoritative list.

**Step 1 – Parse.** Extend `parser.c` to build a `t_request` `{ command, context, argument }`; consult the spec table so numeric arguments are converted immediately when `arg == ARG_INT`.

**Step 2 – Validate.** Create helpers such as `validate_context(&request, spec)` and `validate_arg(&request, spec)` that surface clear errors (`"log" requires an integer count`) before dispatching.

**Step 3 – Dispatch.** Let `cmd.c` resolve the spec and forward the `t_request` to dedicated handlers. Split context-specific logic into files like `src/quests_command.c` or `src/yield_command.c`, each exposing `handle_log`, `handle_add`, etc.

**Step 4 – Iterate with an example.** Start by moving the current quest logic: update the spec entry, implement `handle_log(const t_request *req)` in `src/quests_command.c`, and ensure it reads `req->argument.int_val`. Once that pattern works, follow the same steps for yield and balance features.
