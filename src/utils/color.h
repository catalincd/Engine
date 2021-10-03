#pragma once

#include <cstdint>
#include "../linmath.h"
typedef unsigned int uint;

struct Color
{
	float r, g, b, a;
	Color()
	{
		r = g = b = a = 1.0f;
	}

	Color(float r, float g, float b, float a);

	Color(uint color);

	Color operator*(Color c);

	Color RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a);
};

