#pragma once
#ifndef PhongLyThuyet_H
#define PhongLyThuyet_H
#include <string>
#include "PhongHoc.h"
class PhongLyThuyet : public PhongHoc
{
private:
	bool coMayChieu;
public:
	PhongLyThuyet(const string& maPhong, const string& dayNha, float dienTich, int soBongDen, bool coMayChieu);
	void setcoMayChieu(bool coMayChieu);
	bool getcoMayChieu() const;
	virtual bool datChuan() const override;
	virtual void hienThiThongTin() const override;
};
#endif
