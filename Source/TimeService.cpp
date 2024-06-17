﻿#include "../Header/TimeService.h"

void TimeService::initialize()
{
    previous_time = std::chrono::steady_clock::now();
    delta_time = 0;
}

void TimeService::update()
{
    updateDeltaTime();
}

float TimeService::getDeltaTime() const
{
    return delta_time;
}

void TimeService::updateDeltaTime()
{
    delta_time = calculateDeltaTime();
    updatePreviousTime();
}

float TimeService::calculateDeltaTime() const
{
    // Calculate time difference in microseconds between the current and previous frame.
    const int delta = std::chrono::duration_cast<std::chrono::microseconds>(
        std::chrono::steady_clock::now() - previous_time).count();

    // The cast is used to convert delta time from microseconds into seconds
    return static_cast<float>(delta) / static_cast<float>(1000000);
}

// Update previous_time to the current time
void TimeService::updatePreviousTime()
{
    previous_time = std::chrono::steady_clock::now();
}