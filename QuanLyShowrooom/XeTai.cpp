#include "XeTai.h"

XeTai::XeTai(std::string ma, int namSanXuat, double dungTichDongCo, double triGiaXe, double taiTrong)
    : Xe(ma, namSanXuat, dungTichDongCo, triGiaXe) {
    setTaiTrong(taiTrong);
}

double XeTai::getTaiTrong() const { return taiTrong; }

void XeTai::setTaiTrong(double taiTrong) {
    if (taiTrong >= 0) {
        this->taiTrong = taiTrong;
    }
    else {
        this->taiTrong = 0;
    }
}

double XeTai::tinhThue() const {
    double vat = triGiaXe * 0.1;
    double thueTruocBa = (taiTrong < 950) ? triGiaXe * 0.02 : triGiaXe * 0.05;
    return vat + thueTruocBa;
}

std::string XeTai::toString() const {
    return "Ma: " + ma + ", Nam san xuat: " + std::to_string(namSanXuat) +
        ", Dung tich dong co: " + std::to_string(dungTichDongCo) +
        ", Tri gia xe: " + std::to_string(triGiaXe) +
        ", Tai trong: " + std::to_string(taiTrong);
}
