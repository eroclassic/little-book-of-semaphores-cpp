#include "solution.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

namespace {
void require(bool condition, const std::string& message) {
    if (!condition) {
        std::cerr << "FAIL: " << message << '\n';
        std::exit(EXIT_FAILURE);
    }
}

std::size_t position_of(const std::vector<std::string>& events,
                        const std::string& event) {
    const auto found = std::find(events.begin(), events.end(), event);
    require(found != events.end(), "missing event " + event);
    return static_cast<std::size_t>(std::distance(events.begin(), found));
}
}  // namespace

int main() {
    constexpr int repetitions = 1000;
    for (int run = 0; run < repetitions; ++run) {
        const auto events = run_rendezvous();
        require(events.size() == 4, "expected exactly four events");
        require(position_of(events, "A1") < position_of(events, "B2"),
                "A1 must happen before B2");
        require(position_of(events, "B1") < position_of(events, "A2"),
                "B1 must happen before A2");
    }

    std::cout << "PASS: rendezvous ordering held for " << repetitions
              << " runs\n";
}
