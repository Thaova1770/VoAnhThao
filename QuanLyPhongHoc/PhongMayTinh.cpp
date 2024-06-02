#include "PhongMayTinh.h"

PhongMayTinh::PhongMayTinh(const string& maPhong, const string& dayNha, float dienTich, int soBongDen, int soMayTinh) : PhongHoc(maPhong, dayNha, dienTich, soBongDen), soMayTinh(soMayTinh) {}

void PhongMayTinh::setsoMayTinh(int soMayTinh) {
    this->soMayTinh = soMayTinh;
}

int PhongMayTinh::getsoMayTinh() const {
    return soMayTinh;
}

bool PhongMayTinh::datChuan() const {
    return (getsoBongDen() >= getdienTich() / 10) && (soMayTinh >= getdienTich() / 1.5);
}

void PhongMayTinh::hienThiThongTin() const {
    cout << "Phong may tinh - " << endl;
    PhongHoc::hienThiThongTin();
    cout << "So may tinh: " << soMayTinh << endl;
}