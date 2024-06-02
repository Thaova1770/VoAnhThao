#pragma once
#include <iostream>
#include <string>

using namespace std;

class NhanVien
{
protected:
	string ma;
	string hoTen;
	string ngayVaoLam;
	string soDienThoai;
	double luongCoBan;

public:
	NhanVien(const string& ma, const string& hoTen, const string& ngayVaoLam, const string& soDienThoai, double luongCoBan);
	virtual ~NhanVien();
	string getMa() const;
	void setMa(const string& ma);
	string getHoTen() const;
	void setHoTen(const string& hoTen);
	string getNgayVaoLam() const;
	void setNgayVaoLam(const string& ngayVaoLam);
	string getSoDienThoai() const;
	void setSoDienThoai(const string& soDienThoai);
	double getLuongCoBan() const;
	void setLuongCoBan(double luongCoBan);
	virtual double tinhLuong() const = 0;
	virtual void inThongTin() const;
	bool isDate(const string& date) const;
	string currentDate() const;
	bool isPhone(const string& soDienThoai) const;
};