//
// Created by cb-1 on 11/06/2025.
//

#include "day03.h"
#include <string>
#include <vector>
#include <regex>
#include <iostream>

std::string Day03::part_one(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        std::regex pattern(R"(mul\((\d{1,3}),(\d{1,3})\))");
        std::smatch match;
        int total = 0;

        // Process each string in the input vector
        for (const auto& line : input) {
            // Set the iterator to the beginning of the string
            std::string::const_iterator begin(line.cbegin());
            // Search in the string for the regex pattern
            while (std::regex_search(begin, line.cend(), match, pattern)) {
                int x = std::stoi(match[1].str());
                int y = std::stoi(match[2].str());
                total += x * y;
                begin = match.suffix().first;
            }
        }
        return std::to_string(total);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day03::part_two(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        // Mul pattern
        std::regex token_pattern(R"(do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\))");
        std::smatch match;
        int total = 0;

        // Mul instruction enabled by default
        bool mul_enabled = true;

        // Iterate over the input and process each single line
        for (const auto& line : input) {
            // Iterator
            std::string::const_iterator begin(line.cbegin());

            while (std::regex_search(begin, line.cend(), match, token_pattern)) {
                std::string token = match[0].str();

                if (token == "do()") {
                    mul_enabled = true;
                } else if (token == "don't()") {
                    mul_enabled = false;
                } else if (match[1].matched && match[2].matched && mul_enabled) {
                    int x = std::stoi(match[1].str());
                    int y = std::stoi(match[2].str());
                    total += x * y;
                }

                begin = match.suffix().first;
            }
        }
        return std::to_string(total);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}