#pragma once
#include "vector3.h"

class vector4
{
public:
	float x, y, z, w;

	vector4()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
		w = 0.0f;
	}

	vector4(float f)
	{
		x = y = z = w = f;
	}

	vector4(float _x, float _y, float _z, float _w)
	{
		x = _x;
		y = _y;
		z = _z;
		w = _w;
	}

	vector4(vector3 v, float _w);

	void operator=(vector4 v);

	bool operator==(vector4 v);
	bool operator!=(vector4 v);

	vector4 operator+(vector4 v);
	vector4 operator-(vector4 v);
	vector4 operator*(float f);
	vector4 operator*(vector4 v);
};

