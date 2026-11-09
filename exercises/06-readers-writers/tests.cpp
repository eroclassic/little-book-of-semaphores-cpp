#include "solution.hpp"

#include <cstdlib>
#include <iostream>

int main() {
    constexpr int readers = 8;
    constexpr int writers = 3;
    constexpr int rounds = 1000;
    const auto result = run_readers_writers_exercise(readers, writers, rounds);

    int active_readers = 0;
    bool active_writer = false;
    int completed_reads = 0;
    int completed_writes = 0;
    for (const auto& event : result.events) {
        switch (event.kind) {
            case AccessEventKind::reader_enter:
                if (active_writer) {
                    std::cerr << "FAIL: reader overlapped a writer\n";
                    return EXIT_FAILURE;
                }
                ++active_readers;
                break;
            case AccessEventKind::reader_exit:
                if (active_readers <= 0) {
                    std::cerr << "FAIL: unmatched reader exit\n";
                    return EXIT_FAILURE;
                }
                --active_readers;
                ++completed_reads;
                break;
            case AccessEventKind::writer_enter:
                if (active_writer || active_readers != 0) {
                    std::cerr << "FAIL: writer did not have exclusive access\n";
                    return EXIT_FAILURE;
                }
                active_writer = true;
                break;
            case AccessEventKind::writer_exit:
                if (!active_writer) {
                    std::cerr << "FAIL: unmatched writer exit\n";
                    return EXIT_FAILURE;
                }
                active_writer = false;
                ++completed_writes;
                break;
        }
    }

    if (active_readers != 0 || active_writer ||
        completed_reads != readers * rounds ||
        completed_writes != writers * rounds ||
        result.writes_completed != writers * rounds) {
        std::cerr << "FAIL: incomplete or unbalanced access trace\n";
        return EXIT_FAILURE;
    }
    std::cout << "PASS: all writes completed without access overlap\n";
}
