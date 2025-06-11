//
// Created by cb-1 on 10/06/2025.
//

#pragma once
#include "IDay.h"

class Day02 : public IDay {
    std::string name() const override { return "Day 02"; }
    std::string part_one(const std::vector<std::string>& input) override;
    std::string part_two(const std::vector<std::string>& input) override;
    bool is_report_safe(const std::vector<int>& report, int part);
    bool is_direction_consistent(const std::vector<int>& report);
    bool is_within_diff_limits(const std::vector<int>& report);
    bool is_fully_safe(const std::vector<int>& report);
};