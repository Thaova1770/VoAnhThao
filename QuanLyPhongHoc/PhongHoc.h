#pragma once
#ifndef PhongHoc_H
#define PhongHoc_H

#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

class PhongHoc
{
private:
	string maPhong;
	string dayNha;
	float dienTich;
	int soBongDen;
public:
	PhongHoc(const string& maPhong, const string& dayNha, float dienTich, int soBongDen);
	void setmaPhong(const string& maPhong);
	void setdayNha(const string& dayNha);
	void setdienTich(float dienTich);
	void setsoBongDen(int soBongDen);
	string getmaPhong() const;
	string getdayNha() const;
	float getdienTich() const;
	int getsoBongDen() const;
	bool isDuAnhSang() const;
	virtual bool datChuan() const;
	virtual void hienThiThongTin() const;
};
#endif
