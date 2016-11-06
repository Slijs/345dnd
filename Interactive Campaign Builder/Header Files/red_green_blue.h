#pragma once
/*!
*a structure just designed to have three attributes of red green blue,
*this is to facilitate color management in the project
*/
struct RGB
{
	RGB()
	{
	}
	RGB(const int r, const int g, const int b)
	{
		this->red = r;
		this->green = g;
		this->blue = b;
	}
	int red;
	int green;
	int blue;
};