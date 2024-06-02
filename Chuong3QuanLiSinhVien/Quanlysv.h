#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

class Quanlysv
{
private:
	string maSosv;
	string hoTen;
	int vang;
	float DiemTH, DiemGK, DiemQt;
public:
	friend void nhap(Quanlysv& a);
	friend void xuat(Quanlysv& a);
	void luuFile(ofstream& f);
	void docFile(ifstream& f);
	float DiemQT();
	bool svDuDKduthi();
	bool svHoNguyen();
	bool svCungten(const vector<Quanlysv>& dsSV);
	Quanlysv();
	Quanlysv(string, string, int, double, double);
};