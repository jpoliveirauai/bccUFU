# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repo shape

`bccUFU` is coursework from the Bacharelado em Ciência da Computação at UFU,
organized by period (`1° Período` … `8° Período`) and then by discipline
folder within each period (see README.md for the full period → discipline
mapping). There is **no root-level build, lint, or test** — each discipline
folder is an independent assignment in whatever language/toolchain that
course used, so always work inside the specific assignment folder and use
its own tooling. Four top-level folders break the period pattern — they were
originally independent git repos (their own GitHub remotes, standalone
history) merged into `bccUFU` as plain file copies, not history-preserving
merges:

- **`FlappyNeuron/`** — a standalone C# (.NET) multilayer-perceptron project
  that learns to play Flappy Bird, done as 7th-period Computational
  Intelligence (IC) coursework. Build/run with the standard `dotnet` CLI
  against `FlappyBirdNeuralNetwork/FlappyBirdNeuralNetwork.csproj`.
- **`IC/`** — Iniciação Científica (undergrad research) on embedded
  RTOS/OS comparison. Formerly its own repo (`github.com/jpoliveirauai/IC`).
  **~5GB of vendored third-party RTOS/SDK source was intentionally dropped**
  when merging — see "Removed content" below before assuming anything is
  missing by accident.
- **`TCC/`** — undergrad thesis (phylogenetics / CWE analysis): Python
  scripts (`data/`, `Análise CWE/`) comparing phylogenetic trees (BIONJ,
  Zephyr) built from CWE data. Formerly its own repo
  (`github.com/jpoliveirauai/TCC`).
- **`8° Período/PI/`** — "Projeto Integrador": a PHP/MySQL real-estate
  listing website (vanilla HTML/CSS/JS/jQuery/Bootstrap front end, PHP
  back end, no frameworks per the assignment spec). Formerly its own repo
  (`github.com/jpoliveirauai/PI`), placed under `8° Período` since that's
  the period it was coursework for.

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

## Removed content

The `bccUFU` git history was rewritten on 2026-07-28 to fix repo bloat/slowness
picked up while absorbing `IC/`, `PI/`, and `TCC/` from their own repos. Two
things were deliberately dropped — if something referenced below seems to be
missing, it was removed on purpose, not lost by accident:

- **`IC/` vendored RTOS/SDK source (~5GB, never committed to `bccUFU`).**
  The original `IC` repo had three copies/snapshots of third-party embedded-OS
  source trees (FreeRTOS, Zephyr, TizenRT, MBED OS, amazon-freertos, RIOT,
  Contiki, TinyOS) under `SOs/`, `Iniciação Científica/SOs`, `TCC/SOs`, and
  `TCC/V1/SOs` — none of it original work, and two of the four copies were
  byte-for-byte duplicates of each other. Only content outside any directory
  named `SOs` was copied into `bccUFU/IC/`. **Recovery:** the original `IC`
  repo (with full history and the vendored SDKs) is untouched at
  `github.com/jpoliveirauai/IC` — `git clone` it if the vendor source is ever
  needed again.
- **6 class-recording videos purged from `bccUFU`'s git history (~350MB).**
  `5° Período/Gerenciamento de Banco de Dados/P1/0`–`6` (MP4s with no
  extension) were committed under two different historical paths
  (`5° Período/GBD/P1/...` and later `5° Período/Gerenciamento de Banco de
  Dados/P1/...`) and accounted for most of the repo's `.git` size. Removed
  from every commit via `git filter-repo` — this rewrote all commit hashes.
  The files themselves were **not deleted**: they're still on disk at their
  current path, now covered by a `.gitignore` entry instead of being
  tracked. If that local copy is ever lost, there's no other copy in this
  repo's history to fall back on.

Because history was rewritten, `bccUFU`'s commit hashes no longer match
what may be cached anywhere referencing the old history (e.g. old local
clones, forks) — those need a fresh `git fetch`/`git reset --hard
origin/master`, not a `pull`.

## Working conventions

- Don't add a build/test setup at the repo root — there isn't a unifying
  one, and each assignment already has whatever it needs.
- When editing an assignment, match its existing language/style; don't
  port it to a different toolchain or "modernize" it.
