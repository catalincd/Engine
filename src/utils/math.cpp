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

	bool isPointInRect(const vector2& p, const vector2& pos, const vector2& size, const vector2& origin)
	{
		vector2 posRelative = vector2(pos.x - size.x * origin.x, pos.y - size.y * origin.y);
		if (p.x < posRelative.x || p.x > posRelative.x + size.x || p.y < posRelative.y || p.y > posRelative.y + size.y)
			return false;
		else
			return true;
	}

	bool isPointInRect(const vector2& p, const vector2& pos, const vector2& size)
	{
		return isPointInRect(p, pos, size, vector2(0, 0));
	}

	bool isPointInCircle(const vector2& p, const vector2& pos, const float radius)
	{
		return (squaredDistance(p, pos) < radius * radius);
	}

	float magnitude(const vector2& v)
	{
		return sqrt(v.x * v.x + v.y * v.y);
	}

	vector2 normalize(const vector2& v)
	{
		const float vMagnitude = magnitude(v);

		return vector2(v.x / vMagnitude, v.y / vMagnitude);
	}

	float clamp(const float val, const float minVal, const float maxVal)
	{
		return (val < minVal) ? minVal : ((val > maxVal) ? maxVal : val);
	}

	vector2 clamp(const vector2& val, const vector2& minVal, const vector2& maxVal)
	{
		return vector2(clamp(val.x, minVal.x, maxVal.x), clamp(val.y, minVal.y, maxVal.y));
	}

	vector2 capVector(const vector2& v, const float length)
	{
		if (dp2(v, v) > length * length)
		{
			return normalize(v) * length;
		}
		else
		{
			return v;
		}
	}


	vector2 min(const vector2& a, const vector2& b)
	{
		return vector2(
			min(a.x, b.x),
			min(a.y, b.y)
		);
	}


	float dp2(const vector2 a, const vector2 b)
	{
		return (a.x * b.x) + (a.y * b.y);
	}

	vector2 reflect(vector2 dir, vector2 normal)
	{
		return (dir - normal * 2.0f * (dp2(normal, dir)));
	}

	float squaredDistance(vector2 a, vector2 b)
	{
		vector2 diff = a - b;
		return dp2(diff, diff);
	}

	float sign(vector2 p1, vector2 p2, vector2 p3)
	{
		return (p1.x - p3.x) * (p2.y - p3.y) - (p2.x - p3.x) * (p1.y - p3.y);
	}

	bool isPointInTriangle(vector2 pt, vector2 v1, vector2 v2, vector2 v3)
	{
		float d1, d2, d3;
		bool has_neg, has_pos;

		d1 = sign(pt, v1, v2);
		d2 = sign(pt, v2, v3);
		d3 = sign(pt, v3, v1);

		has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
		has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

		return !(has_neg && has_pos);
	}

	float distance(vector2 a, vector2 b)
	{
		return magnitude(a - b);
	}
}


