#include "NhanVienPartTime.h"
#include <iostream>

NhanVienPartTime::NhanVienPartTime(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, double luongCoBan, int soGioLamMoiTuan, double luongMoiGio)
    : NhanVien(ma, hoTen, ngayVaoLam, soDienThoai, luongCoBan), soGioLamMoiTuan(soGioLamMoiTuan), luongMoiGio(luongMoiGio) {}

double NhanVienPartTime::tinhLuong() const {
    double luongCanBan = luongCoBan * 0.3;
    double lamThemGio = 0;
    int gioLamTrungBinh = min(soGioLamMoiTuan, 40);
    int gioLamTangCa = max(soGioLamMoiTuan - 40, 0);
    double luongSanPham = gioLamTrungBinh * luongMoiGio + gioLamTangCa * luongMoiGio * 1.5;
    return luongCanBan + luongSanPham;
}

void NhanVienPartTime::inThongTin() const {
    NhanVien::inThongTin();
    cout << ", So gio lam viec moi tuan: " << soGioLamMoiTuan << ", Luong moi gio: " << luongMoiGio << endl;
}
