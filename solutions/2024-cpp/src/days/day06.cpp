//
// Created by cb-1 on 11/06/2025.
//

#include "day06.h"
#include <string>
#include <vector>
#include <iostream>
#include "utils/parser.h"

const std::map<Day06::CardinalDirection, std::pair<int, int>> direction_map = {
    {Day06::CardinalDirection::WEST, {-1, 0}},
    {Day06::CardinalDirection::EAST, {1, 0}},
    {Day06::CardinalDirection::NORTH, {0, -1}},
    {Day06::CardinalDirection::SOUTH, {0, 1}},
    {Day06::CardinalDirection::FINISHED, {0, 0}},
};

std::string Day06::part_one(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        auto map = parse_to_2d_char(input);
        auto result = parse_to_2d_char(input);

        // Find guard and initial direction
        CardinalDirection direction;
        std::pair<int, int> guard_pos;
        for (int row = 0; row < map.size(); row++) {
            for (int col = 0; col < map[0].size(); col++) {
                char c = map[row][col];
                if (c == '^') {
                    direction = CardinalDirection::NORTH;
                    guard_pos = {col, row};
                } else if (c == '>') {
                    direction = CardinalDirection::EAST;
                    guard_pos = {col, row};
                } else if (c == 'v') {
                    direction = CardinalDirection::SOUTH;
                    guard_pos = {col, row};
                } else if (c == '<') {
                    direction = CardinalDirection::WEST;
                    guard_pos = {col, row};
                }
            }
        }

        // Process guard movement
        do {
            result[guard_pos.second][guard_pos.first] = 'X';

            // Update direction
            direction = process_movement(map, guard_pos, direction);

            // Move guard
            map[guard_pos.second][guard_pos.first] = '.';
            switch (direction) {
                case CardinalDirection::NORTH:
                    guard_pos.second--;
                    break;
                case CardinalDirection::EAST:
                    guard_pos.first++;
                    break;
                case CardinalDirection::SOUTH:
                    guard_pos.second++;
                    break;
                case CardinalDirection::WEST:
                    guard_pos.first--;
                    break;
                default:
                    break;
            }
            map[guard_pos.second][guard_pos.first] = '^';
        } while (direction != CardinalDirection::FINISHED);

        // Calculating total
        int total = 0;
        for (int row = 0; row < result.size(); row++) {
            for (int col = 0; col < result[0].size(); col++) {
                if (result[row][col] == 'X') {
                    total++;
                }
            }
        }

        return std::to_string(total);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day06::part_two(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        return "No implementation yet";
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

Day06::CardinalDirection Day06::process_movement(const std::vector<std::vector<char>>& map, const std::pair<int, int>& pos, const CardinalDirection& direction) {
    int check_x;
    int check_y;

    switch (direction) {
        case CardinalDirection::NORTH:
            check_x = pos.first;
            check_y = pos.second - 1;
            break;
        case CardinalDirection::EAST:
            check_x = pos.first + 1;
            check_y = pos.second;
            break;
        case CardinalDirection::SOUTH:
            check_x = pos.first;
            check_y = pos.second + 1;
            break;
        case CardinalDirection::WEST:
            check_x = pos.first - 1;
            check_y = pos.second;
            break;
        default:
            break;
    }

    if (check_y < 0 || check_y >= map.size() || check_x < 0 || check_x >= map[0].size()) {
        return CardinalDirection::FINISHED;
    }

    if (check_next_step(map, check_x, check_y)) {
        return direction;
    } else {
        CardinalDirection new_direction = direction;
        std::pair<int, int> offset;

        do {
            new_direction = get_rotated_direction(new_direction);
            offset = direction_map.at(new_direction);
        } while (!check_next_step(map, pos.first + offset.first, pos.second + offset.second));

        return new_direction;
    }
}

Day06::CardinalDirection Day06::get_rotated_direction(const CardinalDirection& direction) {
    int new_angle = (static_cast<int>(direction) + 90) % 360;
    return static_cast<CardinalDirection>(new_angle);
}