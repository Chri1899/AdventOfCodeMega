//
// Created by cb-1 on 08/06/2025.
//

#include "day01.h"
#include <string>
#include <sstream>
#include <algorithm>

// Comapare method
bool compare(int a, int b) {
    return a > b;
}

// Helper method to parse input into two maps
std::pair<std::vector<int>, std::vector<int>> parse_maps(const std::vector<std::string>& input) {
    // Create 2d vector
    std::vector<int> map_a, map_b;
    map_a.reserve(input.size());
    map_b.reserve(input.size());

    for (const auto& line : input) {
        std::istringstream iss(line);
        int num_a, num_b;

        if (!(iss >> num_a >> num_b)) {
            throw std::runtime_error("Failed to parse input");
        }

        map_a.push_back(num_a);
        map_b.push_back(num_b);
    }

    return {map_a, map_b};
}

std::string Day01::part_one(const std::vector<std::string>& input) {
    if (input.empty()) {
        return "Empty input";
    }

    try {
        // Implementation here
        auto [map_a, map_b] = parse_maps(input);

        // Sort maps
        std::sort(map_a.begin(), map_a.end(), compare);
        std::sort(map_b.begin(), map_b.end(), compare);

        // Calculate differences
        int result = 0;
        for (int i = 0; i < map_a.size(); i++) {
            if (compare(map_a[i], map_b[i])) {
                result += map_a[i] - map_b[i];
            } else {
                result += map_b[i] - map_a[i];
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
        auto [map_a, map_b] = parse_maps(input);

        int result = 0;
        // Loop through maps and count each occurence of map_a's entries in map_b
        for (const auto& value : map_a) {
            result += value * std::count(map_b.begin(), map_b.end(), value);
        }

        return std::to_string(result);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}


