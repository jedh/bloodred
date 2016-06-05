#include "Engine\Timer.h"

namespace BRCore
{
    float Timer::GetDelta()
    {
        m_timeCurrent = high_resolution_clock::now();
        m_delta = m_timeCurrent - m_timePrev; 
        m_timePrev = high_resolution_clock::now();

        return m_delta.count();
    }
}