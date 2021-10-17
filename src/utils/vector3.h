#pragma once

class vector3
{
public:
	float x, y, z;

	vector3()
	{
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	vector3(float f)
	{
		x = y = z = f;
	}

	vector3(float _x, float _y, float _z)
	{
		x = _x;
		y = _y;
		z = _z;
	}

	void operator=(vector3 v);

	bool operator==(vector3 v);
	bool operator!=(vector3 v);

	vector3 operator+(vector3 v);
	vector3 operator-(vector3 v);
	vector3 operator*(float f);
	vector3 operator*(vector3 v);
};

