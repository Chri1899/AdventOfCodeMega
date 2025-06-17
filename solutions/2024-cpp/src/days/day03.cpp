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
            std::string::const_iterator searchStart(line.cbegin());
            // Search in the string for the regex pattern
            while (std::regex_search(searchStart, line.cend(), match, pattern)) {
                int x = std::stoi(match[1].str());
                int y = std::stoi(match[2].str());
                total += x * y;
                searchStart = match.suffix().first;
            }
        }

        std::cout << "Total: " << total << "\n";
        return std::to_string(total);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day03::part_two(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    return "Not implemented yet.";
}
