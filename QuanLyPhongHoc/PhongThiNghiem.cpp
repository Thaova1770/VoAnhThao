#include "PhongThiNghiem.h"

PhongThiNghiem::PhongThiNghiem(const string& maPhong, const string& dayNha, float dienTich, int soBongDen, const string& chuyenNganh, int sucChua, bool coBonRua) : PhongHoc(maPhong, dayNha, dienTich, soBongDen), thongTinChuyenNganh(thongTinChuyenNganh), sucChua(sucChua), coBonRua(coBonRua) {}

void PhongThiNghiem::setthongTinChuyenNganh(const string& chuyenNganh) {
    this->thongTinChuyenNganh = thongTinChuyenNganh;
}

void PhongThiNghiem::setsucChua(int sucChua) {
    this->sucChua = sucChua;
}

void PhongThiNghiem::setcoBonRua(bool coBonRua) {
    this->coBonRua = coBonRua;
}

string PhongThiNghiem::getthongTinChuyenNganh() const {
    return thongTinChuyenNganh;
}

int PhongThiNghiem::getsucChua() const {
    return sucChua;
}

bool PhongThiNghiem::getcoBonRua() const {
    return coBonRua;
}

bool PhongThiNghiem::datChuan() const {
    return (getsoBongDen() >= getdienTich() / 10) && coBonRua;
}

void PhongThiNghiem::hienThiThongTin() const {
    cout << "Phong thi nghiem - " << endl;
    PhongHoc::hienThiThongTin();
    cout << "Chuyen nganh: " << thongTinChuyenNganh << endl;
    cout << "Suc chua: " << sucChua << endl;
    cout << "Bon rua: " << (coBonRua ? "Co" : "Khong") << endl;
}
