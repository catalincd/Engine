#pragma once

class vector2
{
public:
	float x, y;

	vector2()
	{
		x = 0.0f;
		y = 0.0f;
	}

	vector2(float f)
	{
		x = y = f;
	}

	vector2(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	void operator=(const vector2& v);

	bool operator==(const vector2& v);

	bool operator!=(const vector2& v);

	vector2 operator+(const vector2& v);
	vector2 operator-(const vector2& v);
	vector2 operator*(float f);
	vector2 operator*(const vector2& v);
	vector2 operator/(const vector2& v);
};

