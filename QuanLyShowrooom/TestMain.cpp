#include <iostream>
#include <vector>
#include <algorithm>
#include "Xe.h"
#include "XeKhach.h"
#include "XeTai.h"

using namespace std;

class QuanLyXe {
private:
    vector<Xe*> danhSachXe;

public:
    ~QuanLyXe() {
        // Hủy tất cả các đối tượng Xe trong danhSachXe
        for (auto xe : danhSachXe) {
            delete xe;
        }
    }

    void themXe(Xe* xe) {
        // Kiểm tra xem xe đã tồn tại trong danh sách chưa
        if (timXe(xe->getMa()) != nullptr) {
            cout << "Xe co ma " << xe->getMa() << " da ton tai.\n";
            delete xe;
        }
        else {
            danhSachXe.push_back(xe);
        }
    }

    int demXeCoThueTruocBaLonHon200Trieu() const {
        int count = 0;
        for (auto xe : danhSachXe) {
            if (xe->tinhThue() > 200000000) {
                count++;
            }
        }
        return count;
    }

    vector<XeKhach*> layDanhSachXeOToKhachNamX(int nam) const {
        vector<XeKhach*> result;
        for (auto xe : danhSachXe) {
            auto xeKhach = dynamic_cast<XeKhach*>(xe);
            if (xeKhach && xeKhach->getNamSanXuat() == nam) {
                result.push_back(xeKhach);
            }
        }
        return result;
    }

    void capNhatTriGiaXe(const string& ma, double triGiaMoi) {
        Xe* xe = timXe(ma);
        if (xe != nullptr) {
            xe->setTriGiaXe(triGiaMoi);
        }
        else {
            cout << "Khong tim thay xe voi ma " << ma << ".\n";
        }
    }

    vector<Xe*> sapXepGiamTheoNamSanXuat() const {
        vector<Xe*> sortedList = danhSachXe;
        sort(sortedList.begin(), sortedList.end(), [](Xe* a, Xe* b) {
            return a->getNamSanXuat() > b->getNamSanXuat();
            });
        return sortedList;
    }

    void them5XeMau() {
        themXe(new XeKhach("F001", 2021, 2.0, 600000000, "xe du lich", 5));
        themXe(new XeKhach("F002", 2020, 3.0, 400000000, "xe bus", 40));
        themXe(new XeKhach("F003", 2019, 1.8, 300000000, "xe du lich", 5));
        themXe(new XeTai("G001", 2017, 2.5, 200000000, 1000));
        themXe(new XeTai("G002", 2022, 3.5, 500000000, 800));
    }

    void xuatDanhSach() const {
        cout << "Danh sach xe:\n";
        cout << "Ma\tNam SX\tDung tich\tTri gia\t\tLoai xe\t\tSo cho/Tai trong\n";
        for (auto xe : danhSachXe) {
            cout << xe->toString() << "\n";
        }
    }

    void menu() {
        int luaChon;
        do {
            cout << "\n=============== Menu ===============\n";
            cout << "1. Them 5 xe mau\n";
            cout << "2. Xuat danh sach xe\n";
            cout << "3. Cap nhat tri gia xe\n";
            cout << "4. Lay danh sach xe o to khach theo nam\n";
            cout << "5. Dem xe co thue truoc ba lon hon 200 trieu\n";
            cout << "6. Sap xep xe giam theo nam san xuat\at\n";
            cout << "0. Thoat\n";
            cout << "====================================\n";
            cout << "Nhap lua chon: ";
            cin >> luaChon;

            switch (luaChon) {
            case 1:
                them5XeMau();
                break;
            case 2:
                xuatDanhSach();
                break;
            case 3: {
                string ma;
                double triGiaMoi;
                cout << "Nhap ma xe can cap nhat tri gia: ";
                cin >> ma;
                cout << "Nhap gia tri moi: ";
                cin >> triGiaMoi;
                capNhatTriGiaXe(ma, triGiaMoi);
                break;
            }
            case 4: {
                int nam;
                cout << "Nhap nam san xuat de lay danh sach xe o to khach: ";
                cin >> nam;
                vector<XeKhach*> dsKhach = layDanhSachXeOToKhachNamX(nam);
                cout << "\nDanh sach xe o to khach san xuat nam " << nam << ":\n";
                for (auto xe : dsKhach) {
                    cout << xe->toString() << "\n";
                }
                break;
            }
            case 5: {
                int count = demXeCoThueTruocBaLonHon200Trieu();
                cout << "\nSo luong xe co so thue truoc ba lon hon 200 trieu: " << count << "\n";
                break;
            }
            case 6: {
                vector<Xe*> sortedList = sapXepGiamTheoNamSanXuat();
                cout << "\nDanh sach xe sap xep giam theo nam san xuat:\n";
                for (auto xe : sortedList) {
                    cout << xe->toString() << "\n";
                }
                break;
            }
            case 0:
                cout << "Thoat chuong trinh.\n";
                break;
            default:
                cout << "Lua chon khong hop le. Vui long chon lai\n";
            }
        } while (luaChon != 0);
    }

private:
    Xe* timXe(const string& ma) const {
        for (auto xe : danhSachXe) {
            if (xe->getMa() == ma) {
                return xe;
            }
        }
        return nullptr;
    }
};

int main() {
    QuanLyXe quanLyXe;
    quanLyXe.menu();
    return 0;
}
