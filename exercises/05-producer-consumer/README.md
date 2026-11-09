# Exercise 5: Producer-consumer

## Prompt

One producer places a sequence of values into a bounded buffer while one consumer removes them. The producer must wait when the buffer is full, and the consumer must wait when it is empty. Preserve the sequence.

## Progressive hints

<details><summary>Hint 1</summary>Track both free slots and available items.</details>
<details><summary>Hint 2</summary>Use one counting semaphore for empty slots and another for filled slots, plus a mutex for the queue.</details>
<details><summary>Hint 3</summary>Initialize empty slots to the buffer capacity and filled slots to zero. Producer acquires an empty slot before enqueueing; consumer acquires an item before dequeueing.</details>

## Run

```sh
cmake --build build --target producer_consumer_tests
ctest --test-dir build -R '^producer_consumer$' --output-on-failure
```

Inspired by the bounded-buffer pattern in Chapter 4 of *The Little Book of Semaphores*.
