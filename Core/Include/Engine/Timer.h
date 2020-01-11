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
			m_delta(0ms) {}

		float GetDelta();
		void Update();
	private:
		time_point<steady_clock> m_timePrev;
		time_point<steady_clock> m_timeCurrent;
		std::chrono::duration<double, std::milli> m_delta;		
	};
}