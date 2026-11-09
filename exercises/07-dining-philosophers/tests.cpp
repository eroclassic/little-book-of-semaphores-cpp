#include "solution.hpp"

#include <cstdlib>
#include <iostream>
#include <vector>

int main() {
    constexpr int philosophers = 5;
    constexpr int meals_each = 500;
    const auto result = run_dining_philosophers_exercise(philosophers, meals_each);

    if (static_cast<int>(result.meals_by_philosopher.size()) != philosophers) {
        std::cerr << "FAIL: wrong number of philosophers in result\n";
        return EXIT_FAILURE;
    }
    for (int p = 0; p < philosophers; ++p) {
        if (result.meals_by_philosopher[p] != meals_each) {
            std::cerr << "FAIL: philosopher " << p << " did not finish all meals\n";
            return EXIT_FAILURE;
        }
    }

    std::vector<bool> eating(philosophers, false);
    std::vector<int> meals_in_trace(philosophers, 0);
    for (const auto& event : result.events) {
        const int p = event.philosopher;
        if (p < 0 || p >= philosophers) {
            std::cerr << "FAIL: invalid philosopher id in trace\n";
            return EXIT_FAILURE;
        }
        if (event.kind == MealEventKind::begin) {
            const int left = (p + philosophers - 1) % philosophers;
            const int right = (p + 1) % philosophers;
            if (eating[p] || eating[left] || eating[right]) {
                std::cerr << "FAIL: neighboring philosophers ate together\n";
                return EXIT_FAILURE;
            }
            eating[p] = true;
            ++meals_in_trace[p];
        } else {
            if (!eating[p]) {
                std::cerr << "FAIL: unmatched meal end event\n";
                return EXIT_FAILURE;
            }
            eating[p] = false;
        }
    }
    for (bool active : eating) {
        if (active) {
            std::cerr << "FAIL: meal trace ended before a philosopher finished eating\n";
            return EXIT_FAILURE;
        }
    }
    for (int p = 0; p < philosophers; ++p) {
        if (meals_in_trace[p] != result.meals_by_philosopher[p]) {
            std::cerr << "FAIL: meal count does not match event trace for philosopher "
                      << p << '\n';
            return EXIT_FAILURE;
        }
    }
    std::cout << "PASS: each philosopher ate and no neighbors overlapped\n";
}
