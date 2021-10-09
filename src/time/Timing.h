#pragma once
#include "../basic.h"
#include "../utils/math.h"


typedef float Timing(float x);

namespace Core
{
	float Linear(float x)
	{
		return x;
	}

	float EaseIn(float x)
	{
		return 1 - cos((x * PI) / 2);
	}

	float EaseOut(float x)
	{
		return sin((x * PI) / 2);
	}

	float Ease(float x)
	{
		return EaseIn(EaseOut(x));
	}

	float ExpoOut(float x)
	{
		return x == 1 ? 1 : 1 - pow(2, -10 * x);
	}

	float EaseCubic(float x)
	{
		return x < 0.5 ? 4 * x * x * x : 1 - pow(-2 * x + 2, 3) / 2;
	}

	float EaseCircular(float x)
	{
		return sqrt(1 - pow(x - 1, 2));
	}

	float Flicker(float x)
	{
		return x == 0
			? 0
			: x == 1
			? 1
			: x < 0.5
			? -(pow(2, 20 * x - 10) * sin((20 * x - 11.125) * c5)) / 2
			: (pow(2, -20 * x + 10) * sin((20 * x - 11.125) * c5)) / 2 + 1;
	}

	float BounceOut(float x)
	{
		if (x < 1 / d1) {
			return n1 * x * x;
		}
		else if (x < 2 / d1) {
			return n1 * (x -= 1.5 / d1) * x + 0.75;
		}
		else if (x < 2.5 / d1) {
			return n1 * (x -= 2.25 / d1) * x + 0.9375;
		}
		else {
			return n1 * (x -= 2.625 / d1) * x + 0.984375;
		}
	}

	float BounceIn(float x)
	{
		return 1 - BounceOut(1 - x);
	}
}

