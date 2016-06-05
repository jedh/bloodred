#pragma once

#include <chrono>

using namespace std::chrono;

namespace BRCore
{
    class Timer
    {
    public:
        Timer() : m_timePrev( high_resolution_clock::now() ) {}

        float                               GetDelta();

    private:
        time_point< high_resolution_clock >   m_timePrev;
        time_point< high_resolution_clock >   m_timeCurrent;
        duration< float, std::milli >         m_delta;
    };
}