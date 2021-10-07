#pragma once

#include "vector2.h"
#include "math.h"
#include <sstream>



namespace Core
{
	const float PI = 3.141592;
	const float d2r = PI / 180.0f;
	const float r2d = 180.0f / PI;

	const float c5 = (2 * PI) / 4.5;
	const float n1 = 7.5625;
	const float d1 = 2.75;

	double min(double a, double b);

	double max(double a, double b);

	float max(float a, float b);

	class Math
	{
	public:
		float DegreeToRadian(float alpha)
		{
			return alpha * d2r;
		}

		float RadianToDegree(float alpha)
		{
			return alpha * r2d;
		}

		vector2 RotatePointAround(vector2 p, vector2 origin, const float angle)
		{
			float s = sin(angle);
			float c = cos(angle);

			p.x -= origin.x;
			p.y -= origin.y;

			float xnew = p.x * c - p.y * s;
			float ynew = p.x * s + p.y * c;

			p.x = xnew + origin.x;
			p.y = ynew + origin.y;
			return p;
		}
	}; 
}