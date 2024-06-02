#include <iostream>
#include "Rectangle.h"
#include "Rectangle.h"
using namespace std;

int main()
{
	CRectangle rect1, * rect2;
	//rect1.heigth = 2;
	rect1.setHeigth(3);
	rect1.setWidth(4);
	cout << "Heigth1: " << rect1.getHeigth() << endl;
	cout << "Width1: " << rect1.getWidth() << endl;
	cout << "S1: " << rect1.area() << endl;

	rect2 = new CRectangle();
	rect2->setHeigth(5);
	rect2->setWidth(4);
	cout << "Heigth2: " << rect2->getHeigth() << endl;
	cout << "Width2: " << rect2->getWidth() << endl;
	cout << "S2: " << rect2->area() << endl;

	return 0;
}