#include "vector4.h"

void vector4::operator=(vector4 v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = v.w;
}

bool vector4::operator==(vector4 v)
{
	return (this->x == v.x && this->y == v.y && this->z == v.z && this->w == v.w);
}
bool vector4::operator!=(vector4 v)
{
	return (this->x != v.x || this->y != v.y || this->z != v.z || this->w != v.w);
}

vector4 vector4::operator+(vector4 v)
{
	return vector4(this->x + v.x, this->y + v.y, this->z + v.z, this->w + v.w);
}

vector4 vector4::operator-(vector4 v)
{
	return vector4(this->x - v.x, this->y - v.y, this->z + v.z, this->w + v.w);
}

vector4 vector4::operator*(float f)
{
	return vector4(this->x * f, this->y * f, this->z * f, this->w * f);
}

vector4 vector4::operator*(vector4 v)
{
	return vector4(this->x * v.x, this->y * v.y, this->z * v.z, this->z * v.w);
}

vector4::vector4(vector3 v, float _w)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
	this->w = _w;
}