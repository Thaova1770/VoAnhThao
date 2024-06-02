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