//
// Created by cb-1 on 11/06/2025.
//

#include "day04.h"
#include <string>
#include <vector>
#include <iostream>

// Directions to check for word
const std::vector<std::pair<int, int>> directions = {
    {0, -1},    // N
    {1, -1},    // NE
    {1, 0},     // E
    {1, 1},     // SE
    {0, 1},     // S
    {-1, 1},    // SW
    {-1, 0},    // W
    {-1, -1}    // NW
};

const std::vector<std::pair<int, int>> directions_part_two = {
    {1, -1},    // NE
    {1, 1},     // SE
    {-1, 1},    // SW
    {-1, -1}    // NW
};

std::string Day04::part_one(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        std::vector<std::string> grid = input;
        const std::string word = "XMAS";
        const int rows = grid.size();
        const int cols = grid[0].size();

        // Result
        int matches = 0;

        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                for (auto [dx, dy] : directions) {
                    bool match = true;

                    int row_inc = row;
                    int col_inc = col;

                    for (int i = 0; i < word.length(); i++) {
                        if (row_inc < 0 || row_inc >= rows || col_inc < 0 || col_inc >= cols || grid[row_inc][col_inc] != word[i]) {
                            match = false;
                            break;
                        }
                        row_inc += dy;
                        col_inc += dx;
                    }
                    if (match) {
                        matches++;
                    }
                }
            }
        }
        return std::to_string(matches);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day04::part_two(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        std::vector<std::string> grid = input;
        const std::string word = "MAS";
        int rows = grid.size();
        int cols = grid[0].size();

        int matches = 0;

        std::vector<std::pair<int, int>> matching_positions;

        // Iterate through each Row
        for (int row = 0; row < rows; row++) {
            // Iterate through each Column
            for (int col = 0; col < cols; col++) {
                // Iterate through each direction
                for (auto [dx, dy] : directions_part_two) {
                    // Check if the word matches in the direction
                    bool match = true;
                    int row_inc = row;
                    int col_inc = col;

                    std::pair<int, int> a_position;

                    for (int i = 0; i < word.length(); i++) {
                        if (row_inc < 0 || row_inc >= rows || col_inc < 0 || col_inc >= cols || grid[row_inc][col_inc] != word[i]) {
                            match = false;
                            break;
                        }

                        // Keep track of A Position
                        if (word[i] == 'A') {
                            a_position = {row_inc, col_inc};
                        }

                        // Increase iterators
                        row_inc += dy;
                        col_inc += dx;
                    }

                    if (match) {
                        matching_positions.push_back(a_position);
                    }
                }
            }
        }

        // Check for double A Positions in vector
        for (int i = 0; i < matching_positions.size(); i++) {
            for (int j = i + 1; j < matching_positions.size(); j++) {
                if (matching_positions[i] == matching_positions[j]) {
                    matches++;
                }
            }
        }
        return std::to_string(matches);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}