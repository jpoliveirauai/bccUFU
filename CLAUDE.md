# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repo shape

`bccUFU` is coursework from the Bacharelado em Ciência da Computação at UFU,
organized by period (`1° Período` … `8° Período`) and then by discipline
folder within each period (see README.md for the full period → discipline
mapping). There is **no root-level build, lint, or test** — each discipline
folder is an independent assignment in whatever language/toolchain that
course used, so always work inside the specific assignment folder and use
its own tooling. Two top-level folders break the period pattern:

- **`FlappyNeuron/`** — a standalone C# (.NET) multilayer-perceptron project
  that learns to play Flappy Bird, done as 7th-period Computational
  Intelligence (IC) coursework. Build/run with the standard `dotnet` CLI
  against `FlappyBirdNeuralNetwork/FlappyBirdNeuralNetwork.csproj`.

Languages span C/C++, Python, Prolog, Java, OCaml, JavaScript, C#, PHP, and
LaTeX depending on the assignment — check the folder for its own scripts
before assuming a toolchain.

## Notable patterns

- **`7° Período/CC/*th/`** (Building Compilers assignments, one folder per
  submission stage) each contain an `exec.sh` that builds the OCaml
  lexer/parser/interpreter pipeline for that stage with `menhir` +
  `ocamlbuild -use-ocamlfind -use-menhir`, producing a `.byte` executable
  loaded interactively via `ocaml`/`rlwrap ocaml`. Later stages
  (`4th`–`6th`) are cumulative reimplementations of the same toy language
  (lexer → parser → semantic analyzer → interpreter → 3-address-code
  generator), not independent programs.
- **`6° Período/Inteligência Artificial/02/`** is the one assignment with a
  `Makefile`; everything else builds via ad-hoc shell scripts or an IDE
  project file (e.g. the Android/Gradle project under `7° Período/CC/1th/`).
- Folders named `Backup`, `.BACKUP`, `*.OLD`, or `(copy)` inside an
  assignment are the student's own prior-attempt snapshots kept alongside
  the current one — not duplicated by mistake, don't consolidate them.

## Working conventions

- Don't add a build/test setup at the repo root — there isn't a unifying
  one, and each assignment already has whatever it needs.
- When editing an assignment, match its existing language/style; don't
  port it to a different toolchain or "modernize" it.
