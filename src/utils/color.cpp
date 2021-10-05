#include "color.h"

Color Color::operator*(Color c)
{
	return Color(this->r * c.r, this->g * c.g, this->b * c.b, this->a * c.a);
}

Color::Color(float r, float g, float b, float a)
{
	this->r = r;
	this->g = g;
	this->b = b;
	this->a = a;
}

Color::Color(uint color)
{
	uint _r, _g, _b, _a;
	_r = (0xFF000000 & color) >> 24;
	_g = (0x00FF0000 & color) >> 16;
	_b = (0x0000FF00 & color) >> 8;
	_a = (0x000000FF & color);
	
	r = float(_r) / 255.0f;
	g = float(_g) / 255.0f;
	b = float(_b) / 255.0f;
	a = float(_a) / 255.0f;
}

Color Color::RGBA(uint8_t r, uint8_t g, uint8_t b, uint8_t a)
{
	return Color(r / 255.0f, g / 255.0f, b / 255.0f, a / 255.0f);
}