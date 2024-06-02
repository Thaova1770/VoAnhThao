#include <iostream>
#include <vector>
#include "NhanVien.h"
#include "NhanVienFullTime.h"
#include "NhanVienPartTime.h"
using namespace std;

void nhapCung(vector<NhanVien*>& employees) {
    employees.push_back(new NhanVienFullTime("FT001", "Vo Thao", "2024-10-15", "0398457271", 1800000, 3.0, 5));
    employees.push_back(new NhanVienFullTime("FT002", "Vo Van Thanh", "2024-06-15", "0388692580 ", 15000000, 2.0, 4));
    employees.push_back(new NhanVienFullTime("FT004", "Le Van Nam", "2022-12-15", "0895423521", 2000000, 2.5, 3));
    employees.push_back(new NhanVienPartTime("PT001", "Nguyen Le Minh", "2018-10-05", "0989437595", 1500000, 35, 100000));
    employees.push_back(new NhanVienPartTime("PT002", "Ho Van Thiet", "2021-08-09", "0978968135", 1600000, 45, 95000));
    employees.push_back(new NhanVienFullTime("FT003", "Truong Phuc Dat", "1990-11-08", "0354987219", 1700000, 2.0, 1));
}

void Menu() {
    cout << "===================MENU=================\n";
    cout << "1. Them nhan vien\n";
    cout << "2. Hien thi danh sach nhan vien da co\n";
    cout << "3. Thoat \n";
    cout << "========================================\n";
    cout << " Noi ban nhap lua chon : ";
}

void themNhanVien(vector<NhanVien*>& employees) {
    string ma, hoTen, ngayVaoLam, soDienThoai;
    double luongCanBan;
    int kieu;
    cout << " Nhap ma nhan vien: "; cin >> ma;
    cout << "Nhap ho va ten nhan vien: "; cin.ignore(); getline(cin, hoTen);
    cout << "Nhap ngay vao lam (DD-MM-YYYY):"; cin >> ngayVaoLam;
    cout << "Nhap so dien thoai: "; cin >> soDienThoai;
    cout << "Nhap luong can ban: "; cin >> luongCanBan;
    do {
        cout << "Nhap loai nhan vien: (1- Toan Thoi Gian , 2 - Ban Thoi Gian): "; cin >> kieu;
    } while (kieu != 1 && kieu != 2);

    if (kieu == 1) {
        double heSoLuong;
        int namKinhNghiem;
        cout << "Nhap he so luong: "; cin >> heSoLuong;
        cout << "Nhap so nam kinh nghiem: "; cin >> namKinhNghiem;
        employees.push_back(new NhanVienFullTime(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan, heSoLuong, namKinhNghiem));
    }
    else {
        int soGioLamViecMoiTuan;
        double luongMoiGio;
        cout << "Nhap so gio lam viec moi tuan: "; cin >> soGioLamViecMoiTuan;
        cout << "Nhap luong moi gio: "; cin >> luongMoiGio;
        employees.push_back(new NhanVienPartTime(ma, hoTen, ngayVaoLam, soDienThoai, luongCanBan, soGioLamViecMoiTuan, luongMoiGio));
    }
}


void danhsachNhanVien(const vector<NhanVien*>& employees) {
    cout << " Danh sach nhan vien: \n";
    cout << "=========================================================\n";
    for (const NhanVien* NhanVien : employees) {
        NhanVien->inThongTin();
    }
    cout << "=========================================================\n";
}

int main() {
    vector<NhanVien*> employees;
    nhapCung(employees);

    int chon;
    do {
        Menu();
        cin >> chon;
        switch (chon) {
        case 1:
            themNhanVien(employees);
            break;
        case 2:
            danhsachNhanVien(employees);
            break;
        case 3:
            cout << "Thoat chuong trinh.\n";
            break;
        default:
            cout << "Nhap khong hop le!!! Vui long nhap lai.\n";
            break;
        }
    } while (chon != 3);
    for (NhanVien* NhanVien : employees) {
        delete NhanVien;
    }
    return 0;
}