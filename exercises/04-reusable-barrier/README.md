# Exercise 4: Reusable barrier

## Prompt

All participating threads repeat a sequence of phases. At the end of each phase, every thread must wait until all participants have arrived before any thread starts the next phase.

Implement `run_reusable_barrier_exercise`. In each phase, increment that phase's arrival count, wait at your barrier, then check that every participant arrived before the barrier opened.

## Progressive hints

<details><summary>Hint 1</summary>A one-use gate is not enough: the barrier must close again for the next phase.</details>
<details><summary>Hint 2</summary>Track arrivals under mutual exclusion and use two turnstiles so one phase drains before the next begins.</details>
<details><summary>Hint 3</summary>Use a count, a mutex, and two semaphores. The first turnstile opens at the final arrival; the second closes the exit until the final departure.</details>

## Run

```sh
cmake --build build --target reusable_barrier_tests
ctest --test-dir build -R '^reusable_barrier$' --output-on-failure
```

Inspired by the reusable barrier pattern in Chapter 3 of *The Little Book of Semaphores*.
