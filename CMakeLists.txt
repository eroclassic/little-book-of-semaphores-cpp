cmake_minimum_required(VERSION 3.20)
project(semaphore_practice LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(Threads REQUIRED)

enable_testing()

function(add_exercise name directory)
    add_executable(${name}_tests
        exercises/${directory}/tests.cpp
        exercises/${directory}/solution.cpp
    )
    target_link_libraries(${name}_tests PRIVATE Threads::Threads)
    target_include_directories(${name}_tests PRIVATE exercises/${directory})
    add_test(NAME ${name} COMMAND ${name}_tests)
    set_tests_properties(${name} PROPERTIES TIMEOUT 15)
endfunction()

add_exercise(rendezvous 01-rendezvous)
add_exercise(mutex 02-mutex)
add_exercise(multiplex 03-multiplex)
add_exercise(reusable_barrier 04-reusable-barrier)
add_exercise(producer_consumer 05-producer-consumer)
add_exercise(readers_writers 06-readers-writers)
add_exercise(dining_philosophers 07-dining-philosophers)
