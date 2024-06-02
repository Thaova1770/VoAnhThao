#include "NhanVienFullTime.h"
#include <iostream>

NhanVienFullTime::NhanVienFullTime(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, double luongCoBan, double heSoLuong, int namKinhNghiem)
    : NhanVien(ma, hoTen, ngayVaoLam, soDienThoai, luongCoBan), heSoLuong(heSoLuong), namKinhNghiem(namKinhNghiem) {}

double NhanVienFullTime::tinhLuong() const {
    double luongTheoHeSo = luongCoBan * heSoLuong;
    double luongTheoKinhNghiem = (namKinhNghiem * 0.05) * luongTheoHeSo;
    return luongTheoHeSo + luongTheoKinhNghiem;
}

void NhanVienFullTime::inThongTin() const {
    NhanVien::inThongTin();
    cout << ", He so luong: " << heSoLuong << ", So nam kinh nghiem: " << namKinhNghiem << endl;
}
#include "NhanVien.h"

class NhanVienPartTime : public NhanVien {
private:
    int soGioLamMoiTuan;
    double luongMoiGio;

public:
    NhanVienPartTime(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, double luongCoBan, int soGioLamMoiTuan, double luongMoiGio);
    double tinhLuong() const override;
    void inThongTin() const override;
};
