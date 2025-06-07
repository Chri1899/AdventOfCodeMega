//
// Created by cb-1 on 08/06/2025.
//

#include "readfile.h"
#include <fstream>
#include <iostream>

std::vector<std::string> read_file_lines(const std::string& path) {
    std::ifstream file(path);
    if (!file.is_open()) {
        std::cerr << "Failed to open file: " << path << "\n";
        return {};
    }

    std::vector<std::string> lines;
    std::string line;
    while (std::getline(file, line)) {
        lines.push_back(line);
    }
    return lines;
}
