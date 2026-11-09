#include "solution.hpp"

#include <cstdlib>
#include <iostream>

int main() {
    constexpr int threads = 8;
    constexpr int increments = 20000;
    const int actual = run_mutex_exercise(threads, increments);
    const int expected = threads * increments;
    if (actual != expected) {
        std::cerr << "FAIL: expected " << expected << ", got " << actual << '\n';
        return EXIT_FAILURE;
    }
    std::cout << "PASS: counter reached " << actual << '\n';
}
