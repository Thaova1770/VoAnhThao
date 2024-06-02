#pragma once
#include "Xe.h"

class XeTai : public Xe {
private:
    double taiTrong;

public:
    XeTai(std::string ma, int namSanXuat, double dungTichDongCo, double triGiaXe, double taiTrong);

    // Getters
    double getTaiTrong() const;

    // Setters
    void setTaiTrong(double taiTrong);

    double tinhThue() const override;
    std::string toString() const override;
};