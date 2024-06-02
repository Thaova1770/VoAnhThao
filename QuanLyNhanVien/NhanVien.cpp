#include "NhanVien.h"
#include <iostream>
#include <ctime>
#include <algorithm>
#include <iomanip> 
using namespace std;

NhanVien::NhanVien(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, double luongCoBan) : ma(ma), hoTen(hoTen), luongCoBan(luongCoBan)
{
    if (!isDate(ngayVaoLam) || ngayVaoLam > currentDate()) {
        this->ngayVaoLam = currentDate();
    }
    if (!isPhone(soDienThoai)) {
        this->soDienThoai = "0000000000";
    }
    else {
        this->soDienThoai = soDienThoai;
    }
}

NhanVien::~NhanVien() {}

string NhanVien::getMa() const {
    return ma;
}

void NhanVien::setMa(const string& ma) {
    this->ma = ma;
}

string NhanVien::getHoTen() const {
    return hoTen;
}

void NhanVien::setHoTen(const string& hoTen) {
    this->hoTen = hoTen;
}

string NhanVien::getNgayVaoLam() const {
    return ngayVaoLam;
}

void NhanVien::setNgayVaoLam(const string& ngayVaoLam) {
    if (isDate(ngayVaoLam) && ngayVaoLam <= currentDate()) {
        this->ngayVaoLam = ngayVaoLam;
    }
    else {
        cout << "Ngay nhap vao khong hop le hoac lon hon ngay hien tai!" << endl;
    }
}

string NhanVien::getSoDienThoai() const {
    return soDienThoai;
}

void NhanVien::setSoDienThoai(const string& soDienThoai) {
    if (isPhone(soDienThoai)) {
        this->soDienThoai = soDienThoai;
    }
}

double NhanVien::getLuongCoBan() const {
    return luongCoBan;
}

void NhanVien::setLuongCoBan(double luongCoBan) {
    if (luongCoBan >= 0) {
        this->luongCoBan = luongCoBan;
    }
}

void NhanVien::inThongTin() const {
    cout << "Ma So: " << ma << ", Ho Ten: " << hoTen << ", Ngay Vao lam: " << ngayVaoLam << ", So Dien Thoai: " << soDienThoai << ", Luong Co Ban: " << luongCoBan;
}

bool NhanVien::isDate(const string& date) const {

    return true;
}

string NhanVien::currentDate() const {
    time_t t = time(0);
    struct tm now;
    localtime_s(&now, &t);
    char buf[11];
    strftime(buf, sizeof(buf), "%d-%m-%Y", &now);
    return buf;
}


bool NhanVien::isPhone(const string& soDienThoai) const {
    return soDienThoai.length() == 10 && soDienThoai[0] == '0' && all_of(soDienThoai.begin(), soDienThoai.end(), ::isdigit);
}