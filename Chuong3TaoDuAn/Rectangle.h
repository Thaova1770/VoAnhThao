//Rectangle.h
#pragma once
class CRectangle
{
private:
	int width, heigth;
public:
	void setWidth(int _width);
	int getWidth() const;
	void setHeigth(int _heigth);
	int getHeigth() const;
	int area();
};
