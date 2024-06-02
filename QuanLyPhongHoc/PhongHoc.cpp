#include "PhongHoc.h"
#include <iomanip>
#include <iostream>

PhongHoc::PhongHoc(const string& maPhong, const string& dayNha, float dienTich, int soBongDen) : maPhong(maPhong), dayNha(dayNha), dienTich(dienTich), soBongDen(soBongDen) {}

void PhongHoc::setmaPhong(const string& maPhong)
{
    this->maPhong = maPhong;
}
void PhongHoc::setdayNha(const string& dayNha)
{
    this->dayNha = dayNha;
}
void PhongHoc::setdienTich(float dienTich)
{
    this->dienTich = dienTich;
}
void PhongHoc::setsoBongDen(int soBongDen)
{
    this->soBongDen = soBongDen;
}
string PhongHoc::getmaPhong() const
{
    return maPhong;
}
string PhongHoc::getdayNha() const
{
    return dayNha;
}
float PhongHoc::getdienTich() const
{
    return dienTich;
}
int PhongHoc::getsoBongDen() const
{
    return soBongDen;
}

bool PhongHoc::isDuAnhSang() const
{
    return (soBongDen / dienTich) >= 10;
}

bool PhongHoc::datChuan() const
{
    return isDuAnhSang();
}

void PhongHoc::hienThiThongTin() const {
    cout << left << setw(15) << "maPhong" << setw(15) << "dayNha" << setw(15) << "dienTich" << setw(15) << "soBongDen" << endl;
    cout << left << setw(15) << maPhong << setw(15) << dayNha << setw(15) << dienTich << setw(15) << soBongDen << endl;
}
