#pragma once
#include <iostream>
class Fraction
{
private:
	int numerator, denominator;
public:
	void print();
	void input();
	Fraction add(Fraction s1, Fraction s2);
	void rg();
	Fraction();
	Fraction(int, int);
};
