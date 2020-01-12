#pragma once
#include <cstdint>

namespace BRCore
{
	struct BRRect
	{
		BRRect() : x(0), y(0), w(0), h(0) {};
		BRRect(float inX, float inY, float inW, float inH) :
			x(inX), y(inY), w(inW), h(inH) {};
		float x, y, w, h;
	};

	struct BRColor
	{
		BRColor(uint8_t inR, uint8_t inG, uint8_t inB, uint8_t inA) :
			r(inR), g(inG), b(inB), a(inA) {};

		uint8_t r, g, b, a;
	};

	struct BRFillRect
	{
		BRFillRect(float inX, float inY, float inW, float inH, BRColor inColor) :
			x(inX), y(inY), w(inW), h(inH), color(inColor) {};

		float x, y, w, h;
		BRColor color;
	};
}