#include "vector2.h"

void vector2::operator=(vector2 v)
{
	this->x = v.x;
	this->y = v.y;
}

bool vector2::operator==(vector2 v)
{
	return (this->x == v.x && this->y == v.y);
}
bool vector2::operator!=(vector2 v)
{
	return (this->x != v.x || this->y != v.y);
}

vector2 vector2::operator+(vector2 v)
{
	return vector2(this->x + v.x, this->y + v.y);
}

vector2 vector2::operator-(vector2 v)
{
	return vector2(this->x - v.x, this->y - v.y);
}

vector2 vector2::operator*(float f)
{
	return vector2(this->x * f, this->y * f);
}

vector2 vector2::operator*(vector2 v)
{
	return vector2(this->x * v.x, this->y * v.y);
}

vector2 vector2::operator/(vector2 v)
{
	return vector2(this->x / v.x, this->y / v.y);
}