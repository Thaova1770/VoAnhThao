#include "Fraction.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main()
{
	int n; cin >> n;
	vector<Fraction> fraction;
	vector<Fraction> fractionUnique;

	// a
	for (int i = 0; i < 100; i++)
	{
		Fraction f(n);
		fraction.push_back(f);
	}
	// b
	cout << "Phan so khong vuot qua 1/2: ";
	for (Fraction& f : fraction)
	{
		if (f <= Fraction(1, 2))
		{
			cout << f << " ";
		}
	}
	cout << endl;
	// c
	sort(fraction.begin(), fraction.end());
	fractionUnique.push_back(fraction[0]);
	for (int i = 1; i < n; i++)
	{
		if (fraction[i] != fraction[i - 1])
		{
			fractionUnique.push_back(fraction[i]);
		}
	}
	cout << "Phan so khong trung nhau: ";
	for (const Fraction& f : fractionUnique)
	{
		cout << f << " ";
	}
	return 0;
}