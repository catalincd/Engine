#include "math.h"


namespace Core
{
	double min(double a, double b)
	{
		return a > b ? b : a;
	}

	double max(double a, double b)
	{
		return a > b ? a : b;
	}

	float max(float a, float b)
	{
		return a > b ? a : b;
	}
}


