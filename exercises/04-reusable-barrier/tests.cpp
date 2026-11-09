#include "solution.hpp"

#include <cstdlib>
#include <iostream>

int main() {
    constexpr int participants = 8;
    constexpr int rounds = 100;
    if (!run_reusable_barrier_exercise(participants, rounds)) {
        std::cerr << "FAIL: not all participants synchronized across every phase\n";
        return EXIT_FAILURE;
    }
    std::cout << "PASS: all threads synchronized across " << rounds << " phases\n";
}
