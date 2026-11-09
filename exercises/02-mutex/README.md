# Exercise 2: Mutex

## Prompt

Several threads increment one shared counter many times. Use a semaphore to protect the update so the final value equals the total number of increments. The starter counter is atomic to keep an incorrect unsynchronized attempt defined in C++; use separate load and store operations so the test can expose lost updates.

## Progressive hints

<details><summary>Hint 1</summary>The read and write that make up an increment must not overlap with another thread's update.</details>
<details><summary>Hint 2</summary>Use one semaphore as a lock around the critical section.</details>
<details><summary>Hint 3</summary>Initialize a binary semaphore to one; acquire before updating and release afterward.</details>

## Run

```sh
cmake --build build --target mutex_tests
ctest --test-dir build -R '^mutex$' --output-on-failure
```

Inspired by the mutex pattern in Chapter 3 of *The Little Book of Semaphores*.
