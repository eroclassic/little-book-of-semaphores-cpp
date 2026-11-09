#pragma once

#include <vector>

enum class AccessEventKind { reader_enter, reader_exit, writer_enter, writer_exit };

struct AccessEvent {
    AccessEventKind kind;
};

struct ReadersWritersResult {
    std::vector<AccessEvent> events;
    int writes_completed;
};

ReadersWritersResult run_readers_writers_exercise(int reader_count,
                                                   int writer_count,
                                                   int rounds);
