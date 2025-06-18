//
// Created by cb-1 on 10/06/2025.
//

#pragma once

#include <vector>
#include <string>
#include <sstream>

std::vector<std::vector<int>> parse_to_columns_int(const std::vector<std::string>& input);
std::vector<std::vector<int>> parse_to_rows_int(const std::vector<std::string>& input);
std::pair<std::vector<std::vector<int>>, std::vector<std::vector<int>>> parse_dual_section_input_to_int(const std::vector<std::string>& input,
                                                                                                        char first_delim,
                                                                                                        char second_delim);