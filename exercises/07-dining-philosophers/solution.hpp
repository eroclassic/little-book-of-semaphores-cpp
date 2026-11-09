#pragma once

#include <vector>

enum class MealEventKind { begin, end };

struct MealEvent {
    int philosopher;
    MealEventKind kind;
};

struct DiningResult {
    std::vector<int> meals_by_philosopher;
    std::vector<MealEvent> events;
};

DiningResult run_dining_philosophers_exercise(int philosophers, int meals_each);
