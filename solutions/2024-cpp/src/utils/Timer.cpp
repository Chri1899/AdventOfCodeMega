//
// Created by cb-1 on 17/06/2025.
//

#include "Timer.h"

Timer::Timer(const std::string& label) : label_(label) {
    start_ = std::chrono::high_resolution_clock::now();
    stopped_ = false;
}

void Timer::stop() {
    if (stopped_) return;
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration<double, std::milli>(end - start_);
    std::cout << "[" << label_ << "] took: " << duration.count() << "ms\n";
    stopped_ = true;
}

Timer::~Timer() {
    stop();
}