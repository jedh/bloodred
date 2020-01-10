#pragma once

#include <chrono>

using namespace std::chrono;

namespace BRCore
{
	class Timer
	{
	public:
		Timer() :
			m_timePrev(steady_clock::now()),
			m_delta(0ms),
			m_lag(0ms),
			m_timestep(16ms) {}

		float                               GetDelta();

	private:
		time_point<steady_clock> m_timePrev;
		time_point<steady_clock> m_timeCurrent;
		std::chrono::duration<double, std::milli> m_delta;
		std::chrono::duration<double, std::milli> m_lag;
		std::chrono::milliseconds m_timestep;
	};
}