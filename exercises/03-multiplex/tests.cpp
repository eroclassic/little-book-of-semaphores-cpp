#include "solution.hpp"

#include <cstdlib>
#include <iostream>

int main() {
    constexpr int capacity = 3;
    const int maximum = run_multiplex_exercise(12, capacity, 2000);
    if (maximum < 1 || maximum > capacity) {
        std::cerr << "FAIL: invalid maximum occupancy " << maximum << '\n';
        return EXIT_FAILURE;
    }
    std::cout << "PASS: maximum occupancy " << maximum << " / " << capacity << '\n';
}
