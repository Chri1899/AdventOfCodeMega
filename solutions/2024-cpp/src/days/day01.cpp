//
// Created by cb-1 on 08/06/2025.
//

#include "day01.h"
#include "../utils/readfile.h"
#include <iostream>
#include <filesystem>

// TODO Fix file reading
void Day01::run() {
    auto lines = read_file_lines("data/2024/test.txt");
    std::cout << "Day 01: Input lines = " << lines.size() << "\n";

    // Print contents to verify
    for (const auto& line : lines) {
        std::cout << "Line: " << line << "\n";
    }
}