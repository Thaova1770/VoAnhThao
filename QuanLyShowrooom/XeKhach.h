#pragma once
#include "Xe.h"

class XeKhach : public Xe {
private:
    std::string loaiXe;
    int soCho;

public:
    XeKhach(std::string ma, int namSanXuat, double dungTichDongCo, double triGiaXe, std::string loaiXe, int soCho);

    // Getters
    std::string getLoaiXe() const;
    int getSoCho() const;

    // Setters
    void setLoaiXe(const std::string& loaiXe);
    void setSoCho(int soCho);

    double tinhThue() const override;
    std::string toString() const override;
};