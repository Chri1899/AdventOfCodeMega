cmake_minimum_required(VERSION 3.31)
project(2024_cpp)

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
        main.cpp
        src/utils/readfile.cpp
        src/days/day01.cpp
)

# Include directories
include_directories(
        ${CMAKE_SOURCE_DIR}/src
)

add_executable(advent ${SOURCES})

