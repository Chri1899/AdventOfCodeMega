//
// Created by cb-1 on 11/06/2025.
//

#include"day05.h"
#include <string>
#include <vector>
#include <iostream>
#include "utils/parser.h"
#include <unordered_set>
#include <queue>

std::string Day05::part_one(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        // Parse input
        auto [rules, updates] = parse_dual_section_input_to_int(input, '|', ',');

        int total = process_updates(updates, rules, 1);
        return std::to_string(total);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day05::part_two(const std::vector<std::string>& input) {
    if (input.empty()) return "Empty input";

    try {
        auto [rules, updates] = parse_dual_section_input_to_int(input, '|', ',');

        int total = process_updates(updates, rules, 2);
        return std::to_string(total);
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

int Day05::process_updates(const std::vector<std::vector<int>>& updates, const std::vector<std::vector<int>>& rules, int part) {
    int total = 0;

    if (part == 1) {
        for (const auto &update: updates) {
            if (check_update_with_rules(update, rules)) {
                total += get_update_middle_page(update);
            }
        }
    } else {
        for (const auto &update : updates) {
            if (!check_update_with_rules(update, rules)) {
                std::vector<int> updated_update = reorder_update(update, rules);
                total += get_update_middle_page(updated_update);
            }
        }
    }
    return total;
}

int Day05::get_update_middle_page(const std::vector<int>& update) {
    return update[update.size() / 2];
}

std::vector<int> Day05::reorder_update(const std::vector<int>& update, const std::vector<std::vector<int>>& rules) {
    std::unordered_map<int, std::unordered_set<int>> graph;
    std::unordered_map<int, int> in_degree;

    // Build graph
    for (int page : update) {
        graph[page] = {};   // Initialize nodes
        in_degree[page] = 0;
    }

    for (const auto& rule : rules) {
        int rule_one = rule[0];
        int rule_two = rule[1];
        if (graph.count(rule_one) && graph.count(rule_two)) {
            if (graph[rule_one].insert(rule_two).second) {
                in_degree[rule_two]++;
            }
        }
    }

    // Kahn's algorithm
    std::queue<int> q;
    for (const auto& [node, degree] : in_degree) {
        if (degree == 0) q.push(node);
    }

    std::vector<int> result;
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            result.push_back(current);
            for (int neighbor : graph[current]) {
                if (--in_degree[neighbor] == 0) q.push(neighbor);
            }
        }

        if (result.size() != update.size()) {
            throw std::runtime_error("Invalid update");
        }

    return result;
}