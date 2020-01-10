#include "Engine\Timer.h"
#include <iostream>

namespace BRCore
{
    float Timer::GetDelta()
    {
        m_timeCurrent = steady_clock::now();
        m_delta = m_timeCurrent - m_timePrev;                          
        m_timePrev = m_timeCurrent;        
        
        // Eventually calculate this lag for rendering.
        //m_lag += m_delta;        
        //std::cout << "timestep: " << m_timestep.count() <<  ", delta: " << m_delta.count() << ", lag:" << m_lag.count() * 0.001 << std::endl;

        return m_delta.count() * 0.001;
    }
}