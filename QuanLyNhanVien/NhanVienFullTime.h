#include "NhanVien.h"

class NhanVienFullTime : public NhanVien {
private:
    double heSoLuong;
    int namKinhNghiem;

public:
    NhanVienFullTime(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, double luongCoBan, double heSoLuong, int namKinhNghiem);
    double tinhLuong() const override;
    void inThongTin() const override;
};