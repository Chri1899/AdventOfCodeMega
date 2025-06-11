//
// Created by cb-1 on 10/06/2025.
//

#include <iostream>
#include "day02.h"
#include "utils/parser.h"

std::string Day02::part_one(const std::vector<std::string>& input) {
    if (input.empty()) {
        return "Empty input";
    }

    try {
        auto reports = parse_to_rows_int(input);
        int safe_count = 0;

        for (const auto& report : reports) {
            if (is_report_safe(report, 1)) {
                ++safe_count;
            }
        }

        return std::to_string(safe_count);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

std::string Day02::part_two(const std::vector<std::string>& input) {
    if (input.empty()) {
        return "Empty input";
    }

    try {
        auto reports = parse_to_rows_int(input);
        int safe_count = 0;

        for (const auto& report : reports) {
            if (is_report_safe(report, 2)) {
                ++safe_count;
            }
        }

        return std::to_string(safe_count);
    } catch (const std::runtime_error& e) {
        return std::string("Error: ") + e.what();
    }
}

bool Day02::is_direction_consistent(const std::vector<int>& report) {
    if (report.size() < 2) return false;
    bool increasing = report[0] < report[1];

    for (size_t i = 0; i < report.size() - 1; ++i) {
        if ((increasing && report[i] > report[i + 1]) ||
            (!increasing && report[i] < report[i + 1])) {
            return false;
        }
    }
    return true;
}

bool Day02::is_within_diff_limits(const std::vector<int>& report) {
    for (size_t i = 0; i < report.size() - 1; ++i) {
        int diff = std::abs(report[i] - report[i + 1]);
        if (diff < 1 || diff > 3) {
            return false;
        }
    }
    return true;
}

bool Day02::is_fully_safe(const std::vector<int>& report) {
    return is_direction_consistent(report) && is_within_diff_limits(report);
}

bool Day02::is_report_safe(const std::vector<int>& report, int part) {
    if (report.size() < 2) return false;

    // Part 1: strict check
    if (is_fully_safe(report)) return true;

    // Part 2: allow one bad level to be removed
    if (part == 2) {
        for (size_t i = 0; i < report.size(); ++i) {
            std::vector<int> modified = report;
            modified.erase(modified.begin() + i);
            if (is_fully_safe(modified)) {
                return true;
            }
        }
    }

    return false;
}
