//
// Created by cb-1 on 08/06/2025.
//

#include "day01.h"
#include <string>

std::string Day01::part_one(const std::vector<std::string>& input) {
    // Test
    return "Line count = " + std::to_string(input.size());
}

std::string Day01::part_two(const std::vector<std::string>& input) {
    // Test
    int char_count = 0;
    for (const auto& line : input) {
        char_count += line.size();
    }
    return "Char count = " + std::to_string(char_count);
}
