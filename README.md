# Semaphore Practice

Small, runnable C++ exercises for learning synchronization through puzzles. The first exercise is rendezvous: two threads must each reach a synchronization point before either continues past it.

The exercises are inspired by Allen B. Downey's *The Little Book of Semaphores*. This repository is an independent C++ learning project, not an official companion to the book.

## Requirements

- C++20 compiler
- CMake 3.20+
- Threads support

## Build and run

```sh
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

## Exercises

1. [Rendezvous](exercises/01-rendezvous/README.md)

Each exercise contains a prompt, progressive hints, an implementation, and a small executable test. Try the puzzle before opening `solution.cpp`.

## Attribution and licensing

See [ATTRIBUTION.md](ATTRIBUTION.md) for the book credit and the distinction between this project's original code and any book-derived material. Original source code is licensed under the MIT License; book-derived text or other adapted material, if added, must retain the applicable Creative Commons terms described there.
