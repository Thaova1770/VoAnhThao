#include "XeKhach.h"

XeKhach::XeKhach(std::string ma, int namSanXuat, double dungTichDongCo, double triGiaXe, std::string loaiXe, int soCho)
    : Xe(ma, namSanXuat, dungTichDongCo, triGiaXe) {
    setLoaiXe(loaiXe);
    setSoCho(soCho);
}

std::string XeKhach::getLoaiXe() const { return loaiXe; }
int XeKhach::getSoCho() const { return soCho; }

void XeKhach::setLoaiXe(const std::string& loaiXe) {
    if (loaiXe == "xe bus" || loaiXe == "xe ban tai" || loaiXe == "xe du lich" || loaiXe == "xe khac") {
        this->loaiXe = loaiXe;
    }
    else {
        this->loaiXe = "xe khac";
    }
}

void XeKhach::setSoCho(int soCho) {
    if (soCho >= 2 && soCho <= 50) {
        this->soCho = soCho;
    }
    else {
        this->soCho = 2;
    }
}

double XeKhach::tinhThue() const {
    double vat = triGiaXe * 0.1;
    double thueTieuThuDacBiet = (soCho >= 5) ? triGiaXe * 0.3 : triGiaXe * 0.5;
    double thueTruocBa;

    if (soCho <= 9) {
        thueTruocBa = triGiaXe * 0.1;
    }
    else if (loaiXe == "xe ban tai") {
        thueTruocBa = triGiaXe * 0.06;
    }
    else {
        thueTruocBa = triGiaXe * 0.02;
    }

    return vat + thueTieuThuDacBiet + thueTruocBa;
}

std::string XeKhach::toString() const {
    return "Ma: " + ma + ", Nam san xuat: " + std::to_string(namSanXuat) +
        ", Dung tich dong co: " + std::to_string(dungTichDongCo) +
        ", Tri gia xe: " + std::to_string(triGiaXe) +
        ", Loai xe: " + loaiXe +
        ", So cho: " + std::to_string(soCho);
}

