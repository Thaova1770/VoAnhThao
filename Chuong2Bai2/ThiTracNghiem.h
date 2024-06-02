#pragma once
#include <string>
#include <fstream>
using namespace std;
class CauhoiTN
{
private:
	string Noidungcauhoi;
	string DapanA;
	string DapanB;
	char DapAnDung;
public:
	void nhap();
	void docfile(ifstream& f);
	void ghifile(ofstream& f);
	void kiemtra();
	void xuat();
	string Xoakhoangtrangthua(const string& s);
	void SetNoidungcauhoi(const string& noidung);
	void SetDapanA(const string& dapanA);
	void SetDapanB(const string& dapanB);
	string GetNoidungcauhoi() const;
	string GetDapanA() const;
	string GetDapanB() const;
	friend bool giongnhau(CauhoiTN cau1, CauhoiTN cau2);
};



