cmake_minimum_required(VERSION 3.20)
project(semaphore_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

add_executable(rendezvous_tests
    exercises/01-rendezvous/tests.cpp
    exercises/01-rendezvous/solution.cpp
)
target_link_libraries(rendezvous_tests PRIVATE Threads::Threads)
target_include_directories(rendezvous_tests PRIVATE exercises/01-rendezvous)

enable_testing()
add_test(NAME rendezvous COMMAND rendezvous_tests)
