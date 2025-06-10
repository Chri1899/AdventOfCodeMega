//
// Created by cb-1 on 08/06/2025.
//

#include "day01.h"
#include "utils/parser.h"
#include "utils/helpers.h"
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

std::string Day01::part_one(const std::vector<std::string>& input) {
    if (input.empty()) {
        return "Empty input";
    }

    try {
        // Implementation here
        auto maps = parse_to_columns_int(input);

        // Sort maps
        std::sort(maps[0].begin(), maps[0].end(), greater_than);
        std::sort(maps[1].begin(), maps[1].end(), greater_than);

        // Calculate differences
        int result = 0;
        for (int i = 0; i < maps[0].size(); i++) {
            if (greater_than(maps[0][i], maps[1][i])) {
                result += maps[0][i] - maps[1][i];
            } else {
                result += maps[1][i] - maps[0][i];
            }
        }

        return std::to_string(result);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day01::part_two(const std::vector<std::string>& input) {
    if (input.empty()) {
        return "Empty input";
    }

    try {
        // Implementation here
        auto maps = parse_to_columns_int(input);

        int result = 0;
        // Loop through maps and count each occurence of map_a's entries in map_b
        for (const auto& value : maps[0]) {
            result += value * std::count(maps[1].begin(), maps[1].end(), value);
        }

        return std::to_string(result);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}


