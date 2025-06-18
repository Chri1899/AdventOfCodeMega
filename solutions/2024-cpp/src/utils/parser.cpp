//
// Created by cb-1 on 10/06/2025.
//

#include <iostream>
#include "parser.h"

std::vector<std::vector<int>> parse_to_columns_int(const std::vector<std::string>& input) {
    std::vector<std::vector<int>> columns;

    for (const auto& line : input) {
        std::istringstream iss(line);
        std::vector<int> values;
        int value;

        // Read all the integers in this line
        while (iss >> value) {
            values.push_back(value);
        }

        if (columns.empty()) {
            // First line: create columns
            columns.resize(values.size());
        } else if (values.size() != columns.size()) {
            throw std::runtime_error("Inconsisten number of columns");
        }

        // Append each value to its corresponding column
        for (size_t i = 0; i < values.size(); i++) {
            columns[i].push_back(values[i]);
        }
    }

    return columns;
}

std::vector<std::vector<int>> parse_to_rows_int(const std::vector<std::string>& input) {
    std::vector<std::vector<int>> rows;

    for (const auto& line : input) {
        std::istringstream iss(line);
        std::vector<int> row_values;
        int value;

        while (iss >> value) {
            row_values.push_back(value);
        }

        rows.push_back(row_values);
    }

    return rows;
}

std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> parse_dual_section_input_to_int(const std::vector<std::string>& input,
                                                                                                        char first_delim,
                                                                                                        char second_delim)
{
    std::vector<std::vector<int>> first_section;
    std::vector<std::vector<int>> second_section;

    bool in_first_section = true;
    for (const auto& line : input) {
        // Check if line break
        if (line.empty()) {
            in_first_section = false;
            continue;
        }

        std::vector<int> values;
        std::stringstream ss(line);
        std::string token;
        char delim = in_first_section ? first_delim : second_delim;

        while (std::getline(ss, token, delim)) {
            values.push_back(std::stoi(token));
        }

        if (in_first_section) {
            first_section.push_back(values);
        } else {
            second_section.push_back(values);
        }
    }

    return {first_section, second_section};
}

std::vector<std::vector<char>> parse_to_2d_char(const std::vector<std::string>& input) {
    std::vector<std::vector<char>> output;
    for (const std::string &line : input) {
        output.emplace_back(line.begin(), line.end());
    }
    return output;
}