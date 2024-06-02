#include <iostream>
#include <cmath>
#include "Fraction.h"
using namespace std;

int main()
{
	Fraction s1, s2, s3;
	cout << "Nhap phan so 1: " << endl;
	s1.input();
	cout << "Nhap phan so 2: " << endl;
	s2.input();
	cout << "Ket qua cua phep cong: ";
	s3 = s3.add(s1, s2);
	s3.rg();
	s3.print();
	return 0;
}