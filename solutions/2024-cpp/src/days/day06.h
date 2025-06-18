//
// Created by cb-1 on 10/06/2025.
//

#pragma once
#include "IDay.h"
#include <unordered_map>

class Day06 : public IDay {
    std::string name() const override { return "Day 05"; }
    std::string part_one(const std::vector<std::string>& input) override;
    std::string part_two(const std::vector<std::string>& input) override;
};