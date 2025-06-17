//
// Created by cb-1 on 10/06/2025.
//

#pragma once
#include "IDay.h"

class Day03 : public IDay {
    std::string name() const override { return "Day 03"; }
    std::string part_one(const std::vector<std::string>& input) override;
    std::string part_two(const std::vector<std::string>& input) override;
};