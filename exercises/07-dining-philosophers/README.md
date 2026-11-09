# Exercise 7: Dining philosophers

## Prompt

Several philosophers repeatedly need the two shared forks beside them to eat. Design synchronization so neighboring philosophers never use the same fork at once and the group does not deadlock.

Implement the exercise and record a begin/end event around each meal. Append events through a mutex-protected log so the test can verify the trace. CTest stops the test if it deadlocks beyond its time limit.

## Progressive hints

<details><summary>Hint 1</summary>One fork semaphore per fork prevents two neighbors from using the same fork.</details>
<details><summary>Hint 2</summary>Deadlock can occur if everyone holds one fork while waiting for the other.</details>
<details><summary>Hint 3</summary>Limit the number of philosophers allowed to try to pick up forks at once to one fewer than the total number.</details>

## Run

```sh
cmake --build build --target dining_philosophers_tests
ctest --test-dir build -R '^dining_philosophers$' --output-on-failure
```

Inspired by the dining philosophers problem in Chapter 4 of *The Little Book of Semaphores*.
