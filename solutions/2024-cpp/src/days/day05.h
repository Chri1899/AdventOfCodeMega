//
// Created by cb-1 on 10/06/2025.
//

#pragma once
#include "IDay.h"
#include <unordered_map>

class Day05 : public IDay {
    std::string name() const override { return "Day 05"; }
    std::string part_one(const std::vector<std::string>& input) override;
    std::string part_two(const std::vector<std::string>& input) override;

    // Rule processing
    bool check_update_with_rules(const std::vector<int>& update, const std::vector<std::vector<int>>& rules);
    bool is_rule_applicable(const std::vector<int>& rule, const std::unordered_map<int, int>& page_indices);

    // Update processing
    int get_update_middle_page(const std::vector<int>& update);
    int process_updates(const std::vector<std::vector<int>>& updates, const std::vector<std::vector<int>>& rules);
};