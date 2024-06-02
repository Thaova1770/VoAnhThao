#include "ThiTracNghiem.h"
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

void CauhoiTN::nhap()
{
	cout << "Nhap noi dung cau hoi: ";
	cin.ignore();
	getline(cin, this->Noidungcauhoi);
	cout << "Nhap dap an A: ";
	getline(cin, this->DapanA);
	cout << "Nhap dap an B: ";
	getline(cin, this->DapanB);
	cout << "Nhap dap an dung (A hoac B): ";
	cin >> this->DapAnDung;
}

void CauhoiTN::docfile(ifstream& f)
{
	getline(f, this->Noidungcauhoi);
	getline(f, this->DapanA);
	getline(f, this->DapanB);
	f >> this->DapAnDung;
	f.ignore();
}

void CauhoiTN::ghifile(ofstream& f)
{
	f << this->Noidungcauhoi << endl;
	f << this->DapanA << endl;
	f << this->DapanB << endl;
	f << this->DapAnDung << endl;
}

void CauhoiTN::kiemtra()
{
	cout << this->Noidungcauhoi << endl;
	cout << "A." << this->DapanA << endl;
	cout << "B." << this->DapanB << endl;

	char chon;
	cout << "Nhap lua chon cua ban (A hoac B): ";
	cin >> chon;
	if (toupper(chon) == toupper(this->DapAnDung))
	{
		cout << "Dung!" << endl;
	}
	else cout << "Sai!" << endl;
}

void CauhoiTN::xuat()
{
	cout << this->Noidungcauhoi << endl;
	cout << "A." << this->DapanA << endl;
	cout << "B." << this->DapanB << endl;
	cout << "Dap an dung: " << this->DapAnDung << endl;
}

string CauhoiTN::Xoakhoangtrangthua(const string& s)
{
	string result;
	bool spaceFound = false;
	for (char c : s)
	{
		if (c != ' ')
		{
			result += c;
			spaceFound = false;
		}
		else
		{
			if (!spaceFound)
			{
				result += c;
				spaceFound = true;
			}
		}
	}
	return result;
}

void CauhoiTN::SetNoidungcauhoi(const string& Noidungcauhoi)
{
	this->Noidungcauhoi = Noidungcauhoi;
}

void CauhoiTN::SetDapanA(const string& DapanA)
{
	this->DapanA = DapanA;
}

void CauhoiTN::SetDapanB(const string& DapanB)
{
	this->DapanB = DapanB;
}

string CauhoiTN::GetNoidungcauhoi() const
{
	return Noidungcauhoi;
}

string CauhoiTN::GetDapanA() const
{
	return DapanA;
}

string CauhoiTN::GetDapanB() const
{
	return DapanB;
}


bool giongnhau(CauhoiTN cau1, CauhoiTN cau2)
{
	return (cau1.Noidungcauhoi == cau2.Noidungcauhoi &&
		cau1.DapanA == cau2.DapanA &&
		cau1.DapanB == cau2.DapanB &&
		cau1.DapAnDung == cau2.DapAnDung);
}
