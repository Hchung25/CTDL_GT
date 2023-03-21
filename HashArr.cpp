#include <iostream>
#include <string>
using namespace std;

struct CanBo
{
     string tenCanBo;
     string ChucVu;
     double Luong;
     CanBo * next;
};

typedef CanBo * dsCanBo;

struct Khoa
{
     string TenKhoa;
     int soCanBo;
     dsCanBo DS;
};
// Tao mang co 11 phan tu
Khoa KHOA[11];

// Ham in danh sach CanBo
void indsCanBo (dsCanBo ds)
{
     CanBo * p;
     p = ds;
     while (p != NULL)
     {
          cout << "Name: " << p->tenCanBo << endl;
          cout << "Position: " << p->ChucVu << endl;
          cout << "Salary: " << p->Luong;
          p = p->next;
     }
}

// Ham in dsach Khoa
void indsKhoa (Khoa K[])
{
     for (int i = 0; i < 11; i++)
     {
          cout << "Department name: " << K[i].TenKhoa << endl;
          cout << "Officer: " << K[i].soCanBo << endl;
          indsCanBo(K[i].DS);
     }
}
// Cap nhat so can bo moi khoa
void capnhatSoCanBo (Khoa *dsKhoa, int SoCanBoMoi, string TenKhoa)
{
     for (int i = 0; i < 11; i++)
     {
          if (dsKhoa[i].TenKhoa == TenKhoa)
               dsKhoa[i].soCanBo = SoCanBoMoi;
               break;
     }
}

// Tim khoa
Khoa* TimKhoa(string tenKhoa, Khoa danhSachKhoa[], int soKhoa) {
    for (int i = 0; i < soKhoa; i++) {
        if (danhSachKhoa[i].TenKhoa == tenKhoa) {
            return &danhSachKhoa[i];
        }
    }
    return NULL;
}

void ThemCanBoVaoDanhSach(string hoTen, string chucVu, int luong, Khoa* K) {
    CanBo* cb = new CanBo;
    cb->tenCanBo = hoTen;
    cb->ChucVu = chucVu;
    cb->Luong = luong;
    cb->next = K->DS;
    K->DS = cb;
    K->soCanBo++;
}
// Them can bo vao khoa
void ThemCanBo(string tenKhoa, string hoTen, string chucVu, int luong, Khoa danhSachKhoa[], int soKhoa) {
    Khoa* K = TimKhoa(tenKhoa, danhSachKhoa, soKhoa);
    if (K != NULL) {
        ThemCanBoVaoDanhSach(hoTen, chucVu, luong, K);
    } else {
        cout << "Khoa " << tenKhoa << " khong ton tai trong danh sach." << endl;
    }
}

/*
Để xóa cán bộ có tên T khỏi danh sách, chúng ta cần thực hiện các bước sau:

Tìm khoa K trong mảng danh sách các khoa.
Nếu K tồn tại trong mảng, tìm cán bộ T trong danh sách cán bộ của khoa K.
Nếu T tồn tại trong danh sách cán bộ của khoa K, xóa cán bộ T khỏi danh sách cán bộ của khoa K.
Nếu T không tồn tại trong danh sách cán bộ của khoa K, báo lỗi và không thực hiện xóa cán bộ.
*/

CanBo* TimCanBo(string hoTen, Khoa* K) {
    CanBo* cb = K->DS;
    CanBo* truocCB = NULL;
    while (cb != NULL) {
        if (cb->tenCanBo == hoTen) {
            if (truocCB != NULL) {
                truocCB->next = cb->next;
            } else {
                K->DS = cb->next;
            }
            K->soCanBo--;
            return cb;
        }
        truocCB = cb;
        cb = cb->next;
    }
    return NULL;
}

void XoaCanBo(string tenKhoa, string hoTen, Khoa danhSachKhoa[], int soKhoa) {
    Khoa* K = TimKhoa(tenKhoa, danhSachKhoa, soKhoa);
    if (K != NULL) {
        CanBo* cb = TimCanBo(hoTen, K);
        if (cb != NULL) {
            delete cb;
            cout << "Da xoa can bo " << hoTen << " khoi danh sach." << endl;
        } else {
            cout << "Can bo " << hoTen << " khong ton tai trong khoa " << K->TenKhoa << "." << endl;
        }
    } else {
        cout << "Khoa " << tenKhoa << " khong ton tai trong danh sach." << endl;
    }
}

// tong luong

float TinhTongLuong(Khoa danhSachKhoa[], int soKhoa) {
    float tongLuong = 0.0f;
    for (int i = 0; i < soKhoa; i++) {
        CanBo* cb = danhSachKhoa[i].DS;
        while (cb != NULL) {
            tongLuong += cb->Luong;
            cb = cb->next;
        }
    }
    return tongLuong;
}