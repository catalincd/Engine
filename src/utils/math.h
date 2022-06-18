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

	bool isPointInRect(const vector2& p, const vector2& pos, const vector2& size, const vector2& origin);

	bool isPointInRect(const vector2& p, const vector2& pos, const vector2& size);

	bool isPointInCircle(const vector2& p, const vector2& pos, const float radius);

	bool isPointInTriangle(vector2 pt, vector2 v1, vector2 v2, vector2 v3);

	float magnitude(const vector2& v);

	vector2 normalize(const vector2& v);

	float clamp(const float val, const float minVal, const float maxVal);

	vector2 clamp(const vector2& val, const vector2& minVal, const vector2& maxVal);

	vector2 capVector(const vector2& v, const float length);

	vector2 min(const vector2& a, const vector2& b);

	float dp2(const vector2 a, const vector2 b);

	vector2 reflect(vector2 dir, vector2 normal);

	float squaredDistance(vector2 a, vector2 b);

	float sign(vector2 p1, vector2 p2, vector2 p3);

	float distance(vector2 a, vector2 b);

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