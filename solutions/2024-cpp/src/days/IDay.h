//
// Created by cb-1 on 07/06/2025.
//

#pragma once
#include <string>
#include <vector>

class IDay {
public:
    virtual std::string name() const = 0;
    virtual std::string part_one(const std::vector<std::string>& input) = 0;
    virtual std::string part_two(const std::vector<std::string>& input) = 0;
    virtual ~IDay() = default;
};

