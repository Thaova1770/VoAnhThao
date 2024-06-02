#include "Quanlysv.h"
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <sstream>
using namespace std;


void Quanlysv::luuFile(ofstream& f)
{
	f << this->maSosv << ";" << this->hoTen << ";" << this->vang << ";" << this->DiemGK << ";" << this->DiemTH << ";" << this->DiemQt << endl;
}
/*void Quanlysv::docFile(ifstream& f)
{
	getline(f, this->maSosv, ';');
	getline(f, this->hoTen, ';');
	getline(f, this->vang, ';');
	getline(f, this->DiemGK, ';');
	getline(f, this->DiemTH, ';');
	getline(f, this->DiemQt, ';');
}*/
float Quanlysv::DiemQT()
{
	if (this->vang <= 5)
	{
		this->DiemQt = (10 - this->vang * 2) * 0.2 + this->DiemTH * 0.3 + this->DiemGK * 0.5;
	}
	else this->DiemQt = 0;
	return this->DiemQt;
}

bool Quanlysv::svDuDKduthi()
{
	return DiemQT() >= 3;
}

bool Quanlysv::svHoNguyen()
{
	return this->hoTen.compare(0, 6, "Nguyen") == 0;
}

bool Quanlysv::svCungten(const vector<Quanlysv>& dsSV)
{
	for (const auto& sv : dsSV)
	{
		if (sv.hoTen == hoTen && &sv != this)
		{
			return true;
		}
	}
	return false;
}



Quanlysv::Quanlysv()
{
	maSosv = hoTen = "";
	vang = 0;
	DiemGK = DiemTH = 0;
}

Quanlysv::Quanlysv(string maSosv, string hoTen, int vang, double DiemGK, double DiemTH)
{
	this->maSosv = maSosv;
	this->hoTen = hoTen;
	this->vang = vang;
	this->DiemGK = DiemGK;
	this->DiemTH = DiemTH;
}

void nhap(Quanlysv& a)
{
	cout << "Ma so sinh vien: "; cin >> a.maSosv;
	cout << "Ho va ten: "; cin.ignore(); getline(cin, a.hoTen);
	cout << "So ngay vang: "; cin >> a.vang;
	cout << "Diem giua ki: "; cin >> a.DiemGK;
	cout << "Diem thuc hanh: "; cin >> a.DiemTH;
}

void xuat(Quanlysv& a)
{
	cout << setw(12) << left << a.maSosv << "\t";
	cout << setw(30) << left << a.hoTen << "\t";
	cout << setw(4) << left << a.vang << "\t";
	cout << setw(6) << left << a.DiemGK << "\t";
	cout << setw(6) << left << a.DiemTH << "\t";
	cout << setw(6) << left << a.DiemQt << "\t";
	cout << endl;
}
