#pragma once
#include <fstream>
using namespace std;
class Fraction
{
private:
    int tu, mau;
public:
    Fraction();
    Fraction(int n);
    Fraction(int tu, int mau);
    //a
    Fraction operator +(const Fraction&) const;
    Fraction operator -(const Fraction&) const;
    Fraction operator *(const Fraction&) const;
    Fraction operator /(const Fraction&) const;
    //b
    bool operator ==(const Fraction&) const;
    bool operator !=(const Fraction&) const;
    bool operator <(const Fraction&) const;
    bool operator >(const Fraction&) const;
    bool operator <=(const Fraction&) const;
    bool operator >=(const Fraction&) const;
    //c
    friend ostream& operator <<(ostream&, const Fraction&);
    friend istream& operator >>(istream&, Fraction&);
};
