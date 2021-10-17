#include "vector3.h"

void vector3::operator=(vector3 v)
{
	this->x = v.x;
	this->y = v.y;
	this->z = v.z;
}

bool vector3::operator==(vector3 v)
{
	return (this->x == v.x && this->y == v.y && this->z == v.z);
}
bool vector3::operator!=(vector3 v)
{
	return (this->x != v.x || this->y != v.y || this->z != v.z);
}

vector3 vector3::operator+(vector3 v)
{
	return vector3(this->x + v.x, this->y + v.y, this->z + v.z);
}

vector3 vector3::operator-(vector3 v)
{
	return vector3(this->x - v.x, this->y - v.y, this->z + v.z);
}

vector3 vector3::operator*(float f)
{
	return vector3(this->x * f, this->y * f, this->z * f);
}

vector3 vector3::operator*(vector3 v)
{
	return vector3(this->x * v.x, this->y * v.y, this->z * v.z);
}