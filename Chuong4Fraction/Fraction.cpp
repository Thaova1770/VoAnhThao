#include "Fraction.h"
#include <cstdlib>
#include <ctime>
using namespace std;

Fraction::Fraction() : tu(0), mau(1) {}
Fraction::Fraction(int tu, int mau) : tu(tu), mau(mau) {}
Fraction::Fraction(int n)
{
	tu = rand() % n + 1;
	mau = rand() % n + 1;
}

Fraction Fraction::operator +(const Fraction& other) const
{
	Fraction f(0);
	f.tu = this->tu * other.mau + this->mau * other.tu;
	f.mau = this->mau * other.mau;
	return f;
}

Fraction Fraction::operator -(const Fraction& other) const
{
	Fraction f(0);
	f.tu = this->tu * other.mau - this->mau * other.tu;
	f.mau = this->mau * other.mau;
	return f;

}

Fraction Fraction::operator *(const Fraction& other) const
{
	Fraction f(0);
	f.tu = this->tu * other.tu;
	f.mau = this->mau * other.mau;
	return f;
}

Fraction Fraction::operator /(const Fraction& other) const
{
	Fraction f(0);
	f.tu = this->tu * other.mau;
	f.mau = this->mau * other.tu;
	return f;
}

bool Fraction::operator ==(const Fraction& other) const
{
	return this->tu * other.mau == this->mau * other.tu;
}

bool Fraction::operator !=(const Fraction& other) const
{
	return !(*this == other);
}

bool Fraction::operator<(const Fraction& other) const
{
	return (tu * other.mau) < (other.tu * mau);
}

bool Fraction::operator>(const Fraction& other) const
{
	return (tu * other.mau) > (other.tu * mau);
}

bool Fraction::operator >=(const Fraction& other) const
{
	return this->tu * other.mau >= this->mau * other.tu;
}

bool Fraction::operator <=(const Fraction& other) const
{
	return this->tu * other.mau <= this->mau * other.tu;
}

ostream& operator <<(ostream& out, const Fraction& f)
{
	out << f.tu << "/" << f.mau;
	return out;
}

istream& operator >>(istream& in, Fraction& f)
{
	in >> f.tu >> f.mau;
	return in;
}