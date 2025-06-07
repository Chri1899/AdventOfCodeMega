//
// Created by cb-1 on 07/06/2025.
//

#include <iostream>
#include <fstream>

int main() {
    std::ifstream inputFile("data/2024/test.txt");

    if (!inputFile) {
        std::cerr << "Could not open file";
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        std::cout << line << std::endl;
    }

    inputFile.close();
    return 0;
}