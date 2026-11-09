# Exercise 6: Readers-writers

## Prompt

Allow multiple readers to inspect shared data together, while writers access it alone. No reader may overlap a writer, and two writers may not overlap each other.

Implement the exercise and record an enter/exit event for each critical-section access in `events`. Protect the event vector so the test can inspect the resulting trace. Record entry after acquiring synchronization and exit before releasing it.

## Progressive hints

<details><summary>Hint 1</summary>Readers can share access, but a writer needs exclusive access.</details>
<details><summary>Hint 2</summary>Use a mutex to protect the reader count and a separate semaphore that excludes writers.</details>
<details><summary>Hint 3</summary>The first reader acquires the room semaphore; the last reader releases it. Writers acquire that semaphore for their whole write.</details>

## Run

```sh
cmake --build build --target readers_writers_tests
ctest --test-dir build -R '^readers_writers$' --output-on-failure
```

This is the reader-preference pattern; a continuous stream of readers can starve writers. Inspired by Chapter 4 of *The Little Book of Semaphores*.
