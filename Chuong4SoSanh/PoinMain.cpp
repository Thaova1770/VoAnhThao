#include "Poin.h"
#include <algorithm>
#include <iostream>
using namespace std;

void nhapThongtin(Point& point, const string& filename)
{
	int Numpoint;
	cout << "Nhap so luong: "; cin >> Numpoint;
	while (Numpoint--)
	{
		double x, y;
		cin >> x >> y;
		point.addPoint(x, y);
	}
	point.saveToFile(filename);
}

void inThongtin(Point& point)
{
	sort(point.pointList.begin(), point.pointList.end());
	cout << "Cac diem sau khi sap xep:" << endl;
	for (const auto& p : point.pointList) {
		cout << "(" << p.getX() << ", " << p.getY() << ")" << endl;
	}
}
int menu()
{
	int chon;
	cout << "================= MENU ==================" << endl;
	cout << "* 1. Nhap cac diem	                     *" << endl;
	cout << "* 2. Doc File                           *" << endl;
	cout << "* 3. in thong tin		                 *" << endl;
	cout << "* 0. Thoat chuong trinh                 *" << endl;
	cout << "=========================================" << endl;
	cin >> chon;
	return chon;
}

int main()
{
	string filename = "points.txt";
	Point point;
	int chon;
	do
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			nhapThongtin(point, filename);
			break;
		case 2:
			point.Docfile(filename);
			break;
		case 3:
			inThongtin(point);
			break;
		case 0:
			break;
		}
	} while (chon != 0);
	return 0;
}