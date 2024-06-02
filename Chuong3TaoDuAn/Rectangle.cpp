//Rectangle.cpp
#include "Rectangle.h"
int CRectangle::getWidth() const
{
	return width;
}
int CRectangle::getHeigth() const
{
	return heigth;
}
void CRectangle::setWidth(int _width)
{
	width = _width;
}
void CRectangle::setHeigth(int _heigth)
{
	heigth = _heigth;
}
int CRectangle::area()
{
	return width * heigth;
}