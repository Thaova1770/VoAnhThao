#pragma once
#ifndef PhongThiNghiem_H
#define PhongThiNghiem_H
#include "PhongHoc.h"

class PhongThiNghiem : public PhongHoc
{
private:
	string thongTinChuyenNganh;
	int sucChua;
	bool coBonRua;
public:
	PhongThiNghiem(const string& maPhong, const string& dayNha, float dienTich, int soBongDen, const string& themThongTinChuyenNganh, int sucChua, bool coBonRua);
	void setthongTinChuyenNganh(const string& thongTinChuyenNganh);
	void setsucChua(int sucChua);
	void setcoBonRua(bool coBonRua);
	string getthongTinChuyenNganh() const;
	int getsucChua() const;
	bool getcoBonRua() const;
	virtual bool datChuan() const override;
	virtual void hienThiThongTin() const override;
};
#endif
