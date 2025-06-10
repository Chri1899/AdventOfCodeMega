//
// Created by cb-1 on 10/06/2025.
//

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