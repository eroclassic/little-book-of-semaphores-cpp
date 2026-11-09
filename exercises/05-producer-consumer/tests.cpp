#include "solution.hpp"

#include <cstdlib>
#include <iostream>

int main() {
    constexpr int item_count = 10000;
    const auto consumed = run_producer_consumer_exercise(item_count, 7);
    if (static_cast<int>(consumed.size()) != item_count) {
        std::cerr << "FAIL: expected " << item_count << " consumed items, got "
                  << consumed.size() << '\n';
        return EXIT_FAILURE;
    }
    for (int i = 0; i < item_count; ++i) {
        if (consumed[i] != i) {
            std::cerr << "FAIL: incorrect item at position " << i << '\n';
            return EXIT_FAILURE;
        }
    }
    std::cout << "PASS: consumed all items in order\n";
}
