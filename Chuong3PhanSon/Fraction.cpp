#include "Fraction.h"
#include "Fraction.h"
#include <iostream>
using namespace std;
Fraction::Fraction()
{
	this->numerator = 0;
	this->denominator = 1;
}
Fraction::Fraction(int numerator, int denominator)
{
	this->numerator = numerator;
	this->denominator = denominator;
}
void Fraction::input()
{
	cout << "Nhap tu so: ";
	cin >> this->numerator;
	do
	{
		cout << "Nhap mau so: "; cin >> this->denominator;
		if (this->denominator == 0) cout << "Moi ban nhap lai" << endl;
	} while (this->denominator == 0);
}
void Fraction::print()
{
	cout << this->numerator << "/" << this->denominator << endl;
}
Fraction Fraction::add(Fraction s1, Fraction s2)
{
	Fraction s3;
	s3.numerator = s1.numerator * s2.denominator + s1.denominator * s2.numerator;
	s3.denominator = s1.denominator * s2.denominator;
	return s3;
}
void Fraction::rg()
{
	int a, b;
	a = abs(this->numerator);
	b = abs(this->denominator);
	while (a != b)
	{
		if (a > b) a -= b;
		else b -= a;
	}
	this->numerator /= a;
	this->denominator /= a;
}
