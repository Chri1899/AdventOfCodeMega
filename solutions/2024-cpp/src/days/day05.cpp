//
// Created by cb-1 on 11/06/2025.
//

#include"day05.h"
#include <string>
#include <vector>
#include <iostream>
#include "utils/parser.h"

std::string Day05::part_one(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        // Parse input
        auto [rules, updates] = parse_dual_section_input_to_int(input, '|', ',');

        int total = process_updates(updates, rules);
        return std::to_string(total);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day05::part_two(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        return "Not yet Implemented";
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

bool Day05::check_update_with_rules(const std::vector<int>& update, const std::vector<std::vector<int>>& rules) {
    if (update.empty() || rules.empty()) return false;

    // Map page as index from update
    std::unordered_map<int, int> index_map;
    for (size_t i = 0; i < update.size(); ++i) {
        index_map[update[i]] = i;
    }

    // Iterate through each rule and validate
    for (const auto& rule : rules) {
        if (!is_rule_applicable(rule, index_map)) return false;
    }

    return true;
}

bool Day05::is_rule_applicable(const std::vector<int>& rule, const std::unordered_map<int, int>& index_map) {
    if (rule.size() != 2) return false;

    // Check if both pages from the rule exist in the update
    auto it_before = index_map.find(rule[0]);
    auto it_after = index_map.find(rule[1]);

    if (it_before != index_map.end() && it_after != index_map.end()) {
        if (it_before->second >= it_after->second) return false;
    }

    return true;
}

int Day05::process_updates(const std::vector<std::vector<int>>& updates, const std::vector<std::vector<int>>& rules) {
    int total = 0;

    for (const auto& update : updates) {
        if (check_update_with_rules(update, rules)) {
            total += get_update_middle_page(update);
        }
    }

    return total;
}

int Day05::get_update_middle_page(const std::vector<int>& update) {
    return update[update.size() / 2];
}