# Semaphore Practice

Small, runnable C++ exercises for learning synchronization through puzzles. Start with rendezvous, then work through six classic synchronization problems. Each folder has a prompt, staged hints, a starter implementation, and tests. The starter implementations are intentionally incomplete; solving them is the point.

The exercises are inspired by Allen B. Downey's *The Little Book of Semaphores*. This repository is an independent C++ learning project, not an official companion to the book.

## Requirements

- C++20 compiler
- CMake 3.20+
- Threads support

## Practice one exercise

```sh
./practice rendezvous
```

That single command configures the project, builds the selected exercise, and runs its test. Replace `rendezvous` with another exercise name, or run `./practice list` to see the choices. Use `./practice all` after completing more exercises. The starter implementations are intentionally incomplete, so their tests fail until you solve them.

## Exercises

1. [Rendezvous](exercises/01-rendezvous/README.md)
2. [Mutex](exercises/02-mutex/README.md)
3. [Multiplex](exercises/03-multiplex/README.md)
4. [Reusable barrier](exercises/04-reusable-barrier/README.md)
5. [Producer-consumer](exercises/05-producer-consumer/README.md)
6. [Readers-writers](exercises/06-readers-writers/README.md)
7. [Dining philosophers](exercises/07-dining-philosophers/README.md)

Each exercise contains a prompt, progressive hints, an incomplete `solution.cpp`, and an executable test. Implement one problem at a time, then run its test target. The tests are expected to fail until you complete the corresponding implementation. They check concrete ordering, exclusion, capacity, progress, or data-integrity requirements; repeated concurrent runs are useful checks, but they do not prove correctness for every possible schedule. CTest applies a timeout to catch deadlocks.

## Attribution and licensing

See [ATTRIBUTION.md](ATTRIBUTION.md) for the book credit and the distinction between this project's original code and any book-derived material. Original source code is licensed under the MIT License; book-derived text or other adapted material, if added, must retain the applicable Creative Commons terms described there.
