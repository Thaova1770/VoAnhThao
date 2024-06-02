#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "ThiTracNghiem.h"
using namespace std;

void taoDeThi(vector<CauhoiTN>& dsCauHoi)
{
    //xoa danh sach khi tao mot ds moi
    dsCauHoi.clear();

    int soCau;
    cout << "Nhap so cau hoi: ";
    cin >> soCau;

    for (int i = 0; i < soCau; ++i) {
        CauhoiTN cau;
        cout << "Nhap thong tin cho cau hoi " << i + 1 << endl;
        cau.nhap();
        dsCauHoi.push_back(cau);
    }
}
void xuatdethi(vector<CauhoiTN>& dsCauHoi)
{
    for (int i = 0; i < dsCauHoi.size(); i++)
    {
        cout << "Cau hoi " << i + 1 << endl;
        dsCauHoi[i].xuat();
        cout << endl;
    }
}
void Docdethi(vector<CauhoiTN>& dsCauHoi, string file)
{
    ifstream inFile(file);
    if (!inFile.is_open())
    {
        cout << "Khong the mo file" << endl;
        return;
    }
    cout << "Dang do file" << endl;
    while (!inFile.eof())
    {
        CauhoiTN cau;
        cau.docfile(inFile);
        dsCauHoi.push_back(cau);
    }
    cout << "Doc file thanh cong" << endl;
    inFile.close();
}
void Xoakhoangtrangthuacau(vector<CauhoiTN>& dsCauHoi, string file)
{
    for (auto& cauhoi : dsCauHoi)
    {
        cauhoi.SetNoidungcauhoi(cauhoi.Xoakhoangtrangthua(cauhoi.GetNoidungcauhoi()));
        cauhoi.SetDapanA(cauhoi.Xoakhoangtrangthua(cauhoi.GetDapanA()));
        cauhoi.SetDapanB(cauhoi.Xoakhoangtrangthua(cauhoi.GetDapanB()));
    }
    cout << "Da xoa khoang trang thua trong de thi." << endl;

    ofstream outFile(file);
    if (!outFile.is_open())
    {
        cout << "Khong the mo file" << endl;
        return;
    }

    for (auto& cauhoi : dsCauHoi) {
        cauhoi.ghifile(outFile);
    }
    cout << "Ghi de thi sau khi xoa khoang trang thua thanh cong." << endl;
    outFile.close();
}
void menu()
{
    cout << "================= MENU ==================" << endl;
    cout << "* 1. Tao de thi trac nghiem             *" << endl;
    cout << "* 2. Doc de thi tu file                 *" << endl;
    cout << "* 3. Xoa khoang trang thua trong de thi *" << endl;
    cout << "* 4. Kiem tra de thi                    *" << endl;
    cout << "* 5. Xuat de thi                        *" << endl;
    cout << "* 6. Thoat chuong trinh                 *" << endl;
    cout << "=========================================" << endl;
}

int main() {
    vector<CauhoiTN> dsCauHoi;
    string tenFile = "Dethi.TTN";
    int choise;
    do
    {
        menu();
        cin >> choise;

        switch (choise)
        {
        case 1:
            taoDeThi(dsCauHoi);
            break;
        case 2:
            Docdethi(dsCauHoi, tenFile);
            break;
        case 3:
            Xoakhoangtrangthuacau(dsCauHoi, tenFile);
            break;

        case 4:
            int soThuTu;
            cout << "Nhap so thu tu cau hoi can kiem tra: ";
            cin >> soThuTu;
            if (soThuTu > 0 && soThuTu <= dsCauHoi.size())
            {
                dsCauHoi[soThuTu - 1].kiemtra();
            }
            else cout << "So thu tu khong hop le." << endl;
            break;
        case 5:
            xuatdethi(dsCauHoi);
            break;
        case 6:
            break;
        }
    } while (choise != 6);

    return 0;
}