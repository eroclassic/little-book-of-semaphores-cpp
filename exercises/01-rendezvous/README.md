# Exercise 1: Rendezvous

## Prompt

Two threads each perform a first action, then reach a rendezvous. They may arrive in either order. Ensure each thread completes its first action before the other thread performs its second action. Do not impose an ordering between the two first actions or between the two second actions.

Implement `run_rendezvous` in `solution.cpp`. The event recorder and test are provided. A correct solution should work regardless of which thread reaches the rendezvous first.

## Progressive hints

<details>
<summary>Hint 1</summary>

There are two required orderings: A's first action precedes B's second, and B's first action precedes A's second.
</details>

<details>
<summary>Hint 2</summary>

Each thread can announce that it has arrived. It should wait for the other thread's announcement before continuing.
</details>

<details>
<summary>Hint 3</summary>

Use two semaphores initialized to zero, one for each arrival. Each thread signals its own arrival semaphore and waits on the other thread's semaphore.
</details>

## Run

From the repository root:

```sh
cmake --build build
./build/rendezvous_tests
```

The source reference is Chapter 3, section “Rendezvous” of *The Little Book of Semaphores*.
