# Exercise 3: Multiplex

## Prompt

Allow several threads to use a shared room at once, but never allow more than a fixed capacity inside. Return the largest number of threads that were inside together.

## Progressive hints

<details><summary>Hint 1</summary>Track how many threads are inside and ensure the count never exceeds capacity.</details>
<details><summary>Hint 2</summary>A counting semaphore can represent the available places.</details>
<details><summary>Hint 3</summary>Initialize it to the room capacity. Acquire before entering and release on exit.</details>

## Run

```sh
cmake --build build --target multiplex_tests
ctest --test-dir build -R '^multiplex$' --output-on-failure
```

Inspired by the multiplex pattern in Chapter 3 of *The Little Book of Semaphores*.
