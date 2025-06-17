//
// Created by cb-1 on 17/06/2025.
//

#pragma once
#include <string>
#include <chrono>
#include <iostream>

class Timer {
public:
    Timer(const std::string& label = "");
    ~Timer();
    void stop();
private:
    std::string label_;
    std::chrono::high_resolution_clock::time_point start_;
    bool stopped_;
};
