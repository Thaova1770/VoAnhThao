#include "Quanlysv.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>

using namespace std;

void NhapSv(vector<Quanlysv>& dsSV)
{
	char chon;
	do
	{
		Quanlysv sv;
		nhap(sv);
		sv.DiemQT();
		dsSV.push_back(sv);

		cout << "Ban co muon tiep tuc (y/n): ";
		cin >> chon;
	} while (chon == 'y');
}
void luuVaoFile(vector<Quanlysv>& dsSV)
{
	ofstream file("dssv.txt");
	for (auto& sv : dsSV)
	{
		sv.luuFile(file);
	}
	file.close();
}
/*void docfile(vector<Quanlysv>& dsSV)
{
	ifstream inFile("dssv.txt");
	while (!inFile.eof())
	{
		Quanlysv sv;
		sv.docFile(inFile);
		dsSV.push_back(sv);
	}

	inFile.close();

}*/
void dsSv(vector<Quanlysv> dsSV)
{
	cout << setw(12) << left << "MSSV" << "\t" << setw(30) << left << "Ho va ten" << "\t" << setw(4) << left << "Vang" << "\t" << setw(6) << left << "DiemGK" << "\t" << setw(6) << left << "DiemTH" << "\t" << setw(6) << left << "DiemQT" << endl;
	for (auto& sv : dsSV)
	{
		xuat(sv);
	}
}
void dsSvDuDK(vector<Quanlysv> dsSV)
{
	cout << setw(12) << left << "MSSV" << "\t" << setw(30) << left << "Ho va ten" << "\t" << setw(4) << left << "Vang" << "\t" << setw(6) << left << "DiemGK" << "\t" << setw(6) << left << "DiemTH" << "\t" << setw(6) << left << "DiemQT" << endl;
	for (auto& sv : dsSV)
	{
		if (sv.DiemQT() >= 3)
		{
			xuat(sv);
		}

	}
}
void dsSvHoNguyen(vector<Quanlysv> dsSV)
{
	cout << setw(12) << left << "MSSV" << "\t" << setw(30) << left << "Ho va ten" << "\t" << setw(4) << left << "Vang" << "\t" << setw(6) << left << "DiemGK" << "\t" << setw(6) << left << "DiemTH" << "\t" << setw(6) << left << "DiemQT" << endl;
	for (auto& sv : dsSV)
	{
		if (sv.svHoNguyen())
		{
			xuat(sv);
		}

	}
}
void dsSvCungten(vector<Quanlysv> dsSV)
{
	cout << setw(12) << left << "MSSV" << "\t" << setw(30) << left << "Ho va ten" << "\t" << setw(4) << left << "Vang" << "\t" << setw(6) << left << "DiemGK" << "\t" << setw(6) << left << "DiemTH" << "\t" << setw(6) << left << "DiemQT" << endl;
	for (auto& sv : dsSV)
	{
		if (sv.svCungten(dsSV))
		{
			xuat(sv);
		}

	}
}
int menu()
{
	int chon;
	cout << "================= MENU ==================" << endl;
	cout << "* 1. Nhap sinh vien	                 *" << endl;
	cout << "* 2. Danh sach sinh vien                *" << endl;
	cout << "* 3. Danh sach sinh vien du dieu kien   *" << endl;
	cout << "* 4. Danh sach sinh vien ho Nguyen      *" << endl;
	cout << "* 5. Danh sach sinh vien cung ten       *" << endl;
	cout << "* 6. Luu vao File                       *" << endl;
	cout << "* 7. Doc File                           *" << endl;
	cout << "* 0. Thoat chuong trinh                 *" << endl;
	cout << "=========================================" << endl;
	cin >> chon;
	return chon;
}
int main()
{
	vector<Quanlysv> dsSV;

	int chon;
	do
	{
		chon = menu();
		switch (chon)
		{
		case 1:
			NhapSv(dsSV);
			break;
		case 2:
			dsSv(dsSV);
			break;
		case 3:
			dsSvDuDK(dsSV);
			break;
		case 4:
			dsSvHoNguyen(dsSV);
			break;
		case 5:
			dsSvCungten(dsSV);
			break;
		case 6:
			luuVaoFile(dsSV);
			break;
			//		case 7:
						//docfile(dsSV);
						//break;
		case 0:
			break;
		}
	} while (chon != 0);

	return 0;
}