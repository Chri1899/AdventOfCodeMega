//
// Created by cb-1 on 10/06/2025.
//

#pragma once
#include "IDay.h"
#include <map>
#include <iostream>

class Day06 : public IDay {

public:
    enum class CardinalDirection {
        NORTH = 0,
        EAST = 90,
        SOUTH = 180,
        WEST = 270,
        FINISHED = 999
    };
private:
    std::string name() const override { return "Day 05"; }
    std::string part_one(const std::vector<std::string>& input) override;
    std::string part_two(const std::vector<std::string>& input) override;

    // Process movement
    CardinalDirection process_movement(const std::vector<std::vector<char>>& map, const std::pair<int, int>& pos, const CardinalDirection& direction);

    // Util
    CardinalDirection get_rotated_direction(const CardinalDirection& direction);
    static bool check_next_step(const std::vector<std::vector<char>>& map, const int& x, const int& y) {
        return map[y][x] == '.';
    }
};