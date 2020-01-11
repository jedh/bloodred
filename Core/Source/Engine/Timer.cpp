#include "Engine\Timer.h"
#include <iostream>

namespace BRCore
{
    float Timer::GetDelta()
    {       
        return m_delta.count();
    }

    void Timer::Update()
    {
        m_timeCurrent = steady_clock::now();
        m_delta = m_timeCurrent - m_timePrev;
        m_timePrev = m_timeCurrent;
    }
}