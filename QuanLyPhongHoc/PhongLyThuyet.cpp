#include "PhongLyThuyet.h"

PhongLyThuyet::PhongLyThuyet(const string& maPhong, const string& dayNha, float dienTich, int soBongDen, bool coMayChieu) : PhongHoc(maPhong, dayNha, dienTich, soBongDen), coMayChieu(coMayChieu) {}
void PhongLyThuyet::setcoMayChieu(bool coMayChieu) {
    this->coMayChieu = coMayChieu;
}

bool PhongLyThuyet::getcoMayChieu() const {
    return coMayChieu;
}

bool PhongLyThuyet::datChuan() const {
    return (getsoBongDen() >= getdienTich() / 10) && coMayChieu;
}

void PhongLyThuyet::hienThiThongTin() const {
    cout << "Phong hoc ly thuyet - " << endl;
    PhongHoc::hienThiThongTin();
    cout << "Co may chieu: " << (coMayChieu ? "Co" : "Khong") << endl;
}