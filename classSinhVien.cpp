#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// Khai báo lớp SinhVien
class SinhVien
{
private:
    string ten;
    int maSV;
    float diem;

public:
    // Hàm tạo mặc định
    SinhVien() {}

    // Hàm tạo có tham số
    SinhVien(string ten, int maSV, float diem)
    {
        this->ten = ten;
        this->maSV = maSV;
        this->diem = diem;
    }

    // Getters
    string getTen() const { return ten; }
    int getMaSV() const { return maSV; }
    float getDiem() const { return diem; }

    // Setters
    void setTen(string ten) { this->ten = ten; }
    void setMaSV(int maSV) { this->maSV = maSV; }
    void setDiem(float diem) { this->diem = diem; }

    // Hàm hiển thị thông tin sinh viên
    void hienThi() const
    {
        cout << "Ten: " << ten << endl;
        cout << "Ma SV: " << maSV << endl;
        cout << "Diem: " << diem << endl;
    }
};

// Khai báo lớp QuanLySinhVien
class QuanLySinhVien
{
private:
    vector<SinhVien> danhSachSV;
    string tenFile;

public:
    // Hàm tạo có tham số
    QuanLySinhVien(string tenFile)
    {
        this->tenFile = tenFile;
        docTuFile();
    }

    // Hàm thêm sinh viên mới
    void themSinhVien(SinhVien sv)
    {
        danhSachSV.push_back(sv);
        ghiVaoFile();
    }

    // Hàm hiển thị danh sách sinh viên
    void hienThiDanhSach() const
    {
        for (int i = 0; i < danhSachSV.size(); i++)
        {
            danhSachSV[i].hienThi();
            cout << endl;
        }
    }

    // Hàm tìm sinh viên theo mã sinh viên
    SinhVien timSinhVien(int maSV) const
    {
        for (int i = 0; i < danhSachSV.size(); i++)
        {
            if (danhSachSV[i].getMaSV() == maSV)
            {
                return danhSachSV[i];
            }
        }

        // Nếu không tìm thấy sinh viên nào thì trả về một đối tượng SinhVien rỗng
        return SinhVien();
    }

    // Hàm xóa sinh viên theo mã sinh viên
    void xoaSinhVien(int maSV)
    {
        for (int i = 0; i < danhSachSV.size(); i++)
        {
            if (danhSachSV[i].getMaSV() == maSV)
            {
                danhSachSV.erase(danhSachSV.begin() + i);
                ghiVaoFile();
                return;
            }
