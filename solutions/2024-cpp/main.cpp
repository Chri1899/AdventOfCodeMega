//
// Created by cb-1 on 08/06/2025.
//

#include <iostream>
#include <sstream>
#include <iomanip>
#include <unordered_map>
#include <memory>
#include <thread>
#include <chrono>
#include "days/IDay.h"
#include "days/day01.h"
#include "utils/readfile.h"
#include "days/day02.h"
#include "days/day03.h"
#include "days/day04.h"
#include "utils/Timer.h"
#include "days/day05.h"
#include "days/day06.h"

std::string get_input_path(int day, bool use_test) {
    std::ostringstream oss;
    oss << "data/2024/day" << std::setw(2) << std::setfill('0') << day << (use_test ? "_test.txt" : "_real.txt");
    return oss.str();
}

int main() {
    std::unordered_map<int, std::unique_ptr<IDay>> days;
    // Add the days here to the map
    days[1] = std::make_unique<Day01>();
    days[2] = std::make_unique<Day02>();
    days[3] = std::make_unique<Day03>();
    days[4] = std::make_unique<Day04>();
    days[5] = std::make_unique<Day05>();
    days[6] = std::make_unique<Day06>();

    // Get user input
    int day;
    std::string mode;
    std::cout << "Enter day number to run (1-25): ";
    std::cin >> day;
    std::cout << "Enter mode (test/real): ";
    std::cin >> mode;

    auto it = days.find(day);
    if (it == days.end()) {
        std::cerr << "No solution implemented for Day " << day << "\n";
        return 1;
    }

    // Run test or real data
    bool use_test = (mode == "test");
    std::string path = get_input_path(day, use_test);
    std::vector<std::string> input = read_file_lines(path);

    // Part One
    {
        Timer timer("Part 1");
        std::cout << "\n[" << it->second->name() << " - Part One]: " << it->second->part_one(input) << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    // Part 2
    {
        Timer timer_two("Part 2");
        std::cout << "[" << it->second->name() << " - Part Two]: " << it->second->part_two(input) << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(250));
    }

    return 0;
}