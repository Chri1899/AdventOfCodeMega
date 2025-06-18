cmake_minimum_required(VERSION 3.31)
project(2024_cpp)

set(CMAKE_CXX_STANDARD 20)

# Gather source files
set(SOURCES
        main.cpp
        src/utils/readfile.cpp
        src/utils/parser.cpp
        src/utils/helpers.cpp
        src/utils/Timer.cpp
        # Add more days here
        src/days/day01.cpp
        src/days/day02.cpp
        src/days/day03.cpp
        src/days/day04.cpp
        src/days/day05.cpp
        src/days/day06.cpp
)

# Include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/src
)

add_executable(advent ${SOURCES})

