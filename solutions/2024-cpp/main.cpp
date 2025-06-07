//
// Created by cb-1 on 08/06/2025.
//

#include <iostream>
#include <memory>
#include <unordered_map>

#include "src/days/IDay.h"
#include "src/days/day01.h"

int main() {
    std::unordered_map<int, std::unique_ptr<IDay>> days;
    days[1] = std::make_unique<Day01>();

    int day;
    std::cout << "Enter day number: ";
    std::cin >> day;

    auto it = days.find(day);
    if (it != days.end()) {
        it->second->run();
    } else {
        std::cout << "Day " << day << " not implemented yet.\n";
    }

    return 0;
}