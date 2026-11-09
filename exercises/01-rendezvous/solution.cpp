#include "solution.hpp"

#include <mutex>
#include <semaphore>
#include <thread>

std::vector<std::string> run_rendezvous() {
    std::vector<std::string> events;
    std::mutex events_mutex;
    std::binary_semaphore a_arrived(0);
    std::binary_semaphore b_arrived(0);

    const auto record = [&](const char* event) {
        std::lock_guard<std::mutex> lock(events_mutex);
        events.emplace_back(event);
    };

    std::thread thread_a([&] {
        record("A1");
        a_arrived.release();
        b_arrived.acquire();
        record("A2");
    });

    std::thread thread_b([&] {
        record("B1");
        b_arrived.release();
        a_arrived.acquire();
        record("B2");
    });

    thread_a.join();
    thread_b.join();
    return events;
}
