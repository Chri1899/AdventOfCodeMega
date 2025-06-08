//
// Created by cb-1 on 07/06/2025.
//

#pragma once
#include "IDay.h"

class Day01 : public IDay {
public:
    std::string name() const override { return "Day 01"; }
    std::string part_one(const std::vector<std::string>& input) override;
    std::string part_two(const std::vector<std::string>& input) override;
};
