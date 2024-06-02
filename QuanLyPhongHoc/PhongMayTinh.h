#pragma once
#ifndef PhongMayTinh_H
#define PhongMayTinh_H
#include "PhongHoc.h"
class PhongMayTinh : public PhongHoc
{
private:
	int soMayTinh;
public:
	PhongMayTinh(const string& maPhong, const string& dayNha, float dienTich, int soBongDen, int soMayTinh);
	void setsoMayTinh(int soMayTinh);
	int getsoMayTinh() const;
	virtual bool datChuan() const override;
	virtual void hienThiThongTin() const override;
};
#endif
