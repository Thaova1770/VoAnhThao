#include <iostream>
#include <vector>
#include <algorithm>
#include "PhongHoc.h"
#include "PhongLyThuyet.h"
#include "PhongMayTinh.h"
#include "PhongThiNghiem.h"

class DanhSachPhongHoc {
private:
    vector<PhongHoc*> danhSachPhong;
public:
    // Constructor khởi tạo danh sách
    DanhSachPhongHoc() {}

    // Destructor
    ~DanhSachPhongHoc() {
        for (PhongHoc* phong : danhSachPhong) {
            delete phong;
        }
    }
    void themPhongHoc(PhongHoc* phong) {
        bool trungMaPhong = false;
        for (PhongHoc* p : danhSachPhong) {
            if (p->getmaPhong() == phong->getmaPhong()) {
                trungMaPhong = true;
                break;
            }
        }
        if (!trungMaPhong) {
            danhSachPhong.push_back(phong);
            cout << "Them phong hoc thanh cong!" << endl;
        }
        else {
            cout << "Ma phong bi trung, khong the them!" << endl;
        }
    }
    PhongHoc* timPhongHoc(const string& maPhong) {
        for (PhongHoc* phong : danhSachPhong) {
            if (phong->getmaPhong() == maPhong) {
                return phong;
            }
        }
        return nullptr;
    }
    void hienThiDanhSach() const {
        cout << "Danh sach cac phong hoc:" << endl;
        for (PhongHoc* phong : danhSachPhong) {
            phong->hienThiThongTin();
        }
    }
    vector<PhongHoc*> layDanhSachDatChuan() const {
        vector<PhongHoc*> danhSachDatChuan;
        for (PhongHoc* phong : danhSachPhong) {
            if (phong->datChuan()) {
                danhSachDatChuan.push_back(phong);
            }
        }
        return danhSachDatChuan;
    }
    void sapXepTheoDayNha() {
        sort(danhSachPhong.begin(), danhSachPhong.end(), [](const PhongHoc* a, const PhongHoc* b) {
            return a->getdayNha() < b->getdayNha();
            });
        hienThiDanhSach();
    }
    void sapXepTheoDienTich() {
        sort(danhSachPhong.begin(), danhSachPhong.end(), [](const PhongHoc* a, const PhongHoc* b) {
            return a->getdienTich() > b->getdienTich();
            });
        hienThiDanhSach();
    }
    void sapXepTheoSoBongDen() {
        sort(danhSachPhong.begin(), danhSachPhong.end(), [](const PhongHoc* a, const PhongHoc* b) {
            return a->getsoBongDen() < b->getsoBongDen();
            });
        hienThiDanhSach();
    }
    void capNhatSoMayTinh(const string& maPhong, int soMayTinh) {
        PhongMayTinh* phongMay = dynamic_cast<PhongMayTinh*>(timPhongHoc(maPhong));
        if (phongMay != nullptr) {
            phongMay->setsoMayTinh(soMayTinh);
            cout << "Cap nhat so may tinh thanh cong!" << endl;
        }
        else {
            cout << "Khong tim thay phong may tinh co ma phong " << maPhong << "!" << endl;
        }
    }
    void xoaPhongHoc(const string& maPhong) {
        for (auto it = danhSachPhong.begin(); it != danhSachPhong.end(); ++it) {
            if ((*it)->getmaPhong() == maPhong) {
                delete* it;
                danhSachPhong.erase(it);
                cout << "Xoa phong hoc thanh cong!" << endl;
                return;
            }
        }
        cout << "Khong tim thay phong hoc co ma phong " << maPhong << "!" << endl;
    }
    int tongSoPhongHoc() const {
        return danhSachPhong.size();
    }
    vector<PhongHoc*> layDanhSachPhongMay60May() const {
        vector<PhongHoc*> danhSachPhongMay60;
        for (PhongHoc* phong : danhSachPhong) {
            PhongMayTinh* phongMay = dynamic_cast<PhongMayTinh*>(phong);
            if (phongMay != nullptr && phongMay->getsoMayTinh() == 60) {
                danhSachPhongMay60.push_back(phong);
            }
        }
        hienThiDanhSach();
        return danhSachPhongMay60;
    }
    void taoCung6PhongHoc() {
        themPhongHoc(new PhongLyThuyet("LT01", "F01", 45.5, 10, true));
        themPhongHoc(new PhongMayTinh("MT01", "F02", 95.0, 20, 20));
        themPhongHoc(new PhongThiNghiem("TN01", "F03", 80.0, 25, "Hoa", 30, true));
        themPhongHoc(new PhongLyThuyet("LT02", "F04", 60.0, 35, false));
        themPhongHoc(new PhongMayTinh("MT02", "F05", 150.0, 45, 80));
        themPhongHoc(new PhongThiNghiem("TN02", "F06", 100.0, 40, "Vat Ly", 50, false));
    }
};

void menu() {
    cout << "============================ MENU ============================ " << endl;
    cout << "1. Them phong hoc" << endl;
    cout << "2. Tim kiem phong hoc" << endl;
    cout << "3. Hien thi danh sach phong hoc" << endl;
    cout << "4. Hien thi danh sach cac phong hoc dat chuan" << endl;
    cout << "5. Sap xep danh sach theo day nha" << endl;
    cout << "6. Sap xep danh sach theo dien tich" << endl;
    cout << "7. Sap xep danh sach theo so bong den" << endl;
    cout << "8. Cap nhat so may tinh cho mot phong may tinh" << endl;
    cout << "9. Xoa phong hoc" << endl;
    cout << "10.Tinh tong so phong hoc" << endl;
    cout << "11.Lay danh sach phong may co 60 may tinh" << endl;
    cout << "12.Tao cung 6 phong hoc" << endl;
    cout << "13.Kiem tra phong hoc co du anh sang" << endl;
    cout << "14.Thoat" << endl;
    cout << "==============================================================" << endl;
    cout << "Nhap lua chon cua ban: ";
}

int main() {
    DanhSachPhongHoc danhSach;
    int luaChon;
    do {
        menu();
        cin >> luaChon;
        cin.ignore();

        switch (luaChon) {
        case 1: {
            cout << "Nhap thong tin phong hoc " << endl;
            string maPhong, dayNha;
            float dienTich;
            int soBongDen;
            cout << "maPhong: ";
            cin >> maPhong;
            cout << "dayNha: ";
            cin >> dayNha;
            cout << "dienTich:";
            cin >> dienTich;
            cout << "soBongDen: ";
            cin >> soBongDen;

            cout << "Loai phong hoc (1: Ly thuyet, 2: May tinh, 3: Thi nghiem): ";
            string loaiPhong;
            cin >> loaiPhong;

            if (loaiPhong == "1") {
                bool coMayChieu;
                cout << "Co may chieu (1: Co, 0: Khong): ";
                cin >> coMayChieu;
                danhSach.themPhongHoc(new PhongLyThuyet(maPhong, dayNha, dienTich, soBongDen, coMayChieu));
            }
            else if (loaiPhong == "2") {
                int soMayTinh;
                cout << "So may tinh: ";
                cin >> soMayTinh;
                danhSach.themPhongHoc(new PhongMayTinh(maPhong, dayNha, dienTich, soBongDen, soMayTinh));
            }
            else if (loaiPhong == "3") {
                string chuyenNganh;
                int sucChua;
                bool coBonRua;
                cout << "Chuyen nganh: ";
                cin.ignore();
                getline(cin, chuyenNganh);
                cout << "Suc chua: ";
                cin >> sucChua;
                cout << "Co bon rua (1: Co, 0: Khong): ";
                cin >> coBonRua;
                danhSach.themPhongHoc(new PhongThiNghiem(maPhong, dayNha, dienTich, soBongDen, chuyenNganh, sucChua, coBonRua));
            }
            break;
        }
        case 2: {
            cout << "Nhap ma phong can tim kiem: ";
            string maPhong;
            cin >> maPhong;
            PhongHoc* phong = danhSach.timPhongHoc(maPhong);
            if (phong != nullptr) {
                cout << "Thong tin phong hoc tim duoc:" << endl;
                phong->hienThiThongTin();
            }
            else {
                cout << "Khong tim thay phong hoc co ma phong " << maPhong << "!" << endl;
            }
            break;
        }
        case 3:
            danhSach.hienThiDanhSach();
            break;
        case 4: {
            vector<PhongHoc*> danhSachDatChuan = danhSach.layDanhSachDatChuan();
            cout << "Danh sach cac phong hoc dat chuan:" << endl;
            for (PhongHoc* phong : danhSachDatChuan) {
                phong->hienThiThongTin();
            }
            break;
        }
        case 5:
            danhSach.sapXepTheoDayNha();
            cout << "Da sap xep danh sach theo day nha!" << endl;
            danhSach.hienThiDanhSach();
            break;
        case 6:
            danhSach.sapXepTheoDienTich();
            cout << "Da sap xep danh sach theo dien tich!" << endl;
            danhSach.hienThiDanhSach();
            break;
        case 7:
            danhSach.sapXepTheoSoBongDen();
            cout << "Da sap xep danh sach theo so bong den!" << endl;
            danhSach.hienThiDanhSach();
            break;
        case 8: {
            string maPhong;
            int soMayTinh;
            cout << "Nhap ma phong can cap nhat so may tinh: ";
            cin >> maPhong;
            cout << "Nhap so may tinh moi: ";
            cin >> soMayTinh;
            danhSach.capNhatSoMayTinh(maPhong, soMayTinh);
            break;
        }
        case 9: {
            string maPhong;
            cout << "Nhap ma phong can xoa: ";
            cin >> maPhong;
            danhSach.xoaPhongHoc(maPhong);
            break;
        }
        case 10:
            cout << "Tong so phong hoc: " << danhSach.tongSoPhongHoc() << endl;
            break;
        case 11: {
            vector<PhongHoc*> danhSachPhongMay60 = danhSach.layDanhSachPhongMay60May();
            cout << "Danh sach phong may co 60 may tinh:" << endl;
            for (PhongHoc* phong : danhSachPhongMay60) {
                phong->hienThiThongTin();
            }
            break;
        }
        case 12:
            danhSach.taoCung6PhongHoc();
            cout << "Da tao 6 mau phong hoc va day la danh sach." << endl;
            danhSach.hienThiDanhSach();
            break;
        case 13: {
            cout << "Nhap ma phong can kiem tra: ";
            string maPhong;
            cin >> maPhong;
            PhongHoc* phong = danhSach.timPhongHoc(maPhong);
            if (phong != nullptr) {
                if (phong->isDuAnhSang()) {
                    cout << "Phong hoc co du anh sang." << endl;
                }
                else {
                    cout << "Phong hoc khong du anh sang." << endl;
                }
            }
            else {
                cout << "Khong tim thay phong hoc co ma phong " << maPhong << "!" << endl;
            }
            break;
        }
        case 14:
            cout << "Ket thuc chuong trinh!" << endl;
            break;
        default:
            cout << "Lua chon khong hop le! Vui long nhap lai." << endl;
            break;
        }
    } while (luaChon != 14);

    return 0;
}
