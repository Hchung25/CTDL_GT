#include <iostream>
#include <string>
using namespace std;
// string HK[4] = {"Tot", "Kha", "TrBinh", "Yeu"};
struct SINHVIEN 
{
     int maSV;
     string tenSV;
     string lop;
     double dtk;
     string hk;
     SINHVIEN * next;
};

typedef SINHVIEN * list;
list first, last;

struct node 
{
     SINHVIEN data;
     node * tiep;
};

void KhoiTao (list &first, list &last)
{
     first = NULL;
     last = NULL;
}

SINHVIEN * CreateElement (int maSV, string tenSV, string lop, double dtk, string hk)
{
     SINHVIEN * p;
     p = new(SINHVIEN);
     p->maSV = maSV;
     p->tenSV = tenSV;
     p->lop = lop;
     p->dtk = dtk;
     p->hk = hk;
     p->next = NULL;
     return p;
}

void checkNULL (list first, list last)
{
     if ((first == NULL) && (first->next == NULL))
          cout << "Danh sach nullprt" << endl;
}

void ThemCuoi (list &first, list &last)
{
     SINHVIEN * p;
     if (first == NULL)
     {
          first = p;
          last = p;
     }
     else{
          last->next = p;
          last = p;
     }
}

SINHVIEN * findLop (list first, list last, string lopf)
{
     SINHVIEN * p;
     p = first;
     while (p->next != NULL)
     {
          if (p->lop.compare(lopf) == 0)
               return p;
          p = p->next;
     }
}

void sort_by_maSV(list &ds)
{
     SINHVIEN * p;
     while (p->next != NULL)
     {
          SINHVIEN * q;
          q = p->next;
          while (p->next != NULL)
          {
               if (p->maSV > q->maSV)
               {
                    int tmaSV = p->maSV;
                    p->maSV = q->maSV;
                    q->maSV = tmaSV;

                    string tTenSV = p->tenSV;
                    p->tenSV = q->tenSV;
                    q->tenSV = tTenSV;

                    string tLop = p->lop;
                    p->lop = q->lop;
                    q->lop = tLop;

                    double tdtk = p->dtk;
                    p->dtk = q->dtk;
                    q->dtk = tdtk;

                    string thk = p->hk;
                    p->hk = q->hk;
                    q->hk = thk;
               }
          }
     }
}

void XoaCuoi (list &first, list &last)
{
     SINHVIEN * p;
     p = first;
     while (p->next != last)
     {
          p = p->next;
     }
     last = p;
     p = last;
     last->next = NULL;
     delete p;
}
void DisPlay (list first, list last)
{
     SINHVIEN * p;
     p = first;
     while (p->next != NULL)
     {
          cout << "MA SINH VIEN: " << p->maSV << endl;
          cout << "TEN SINH VIEN: " << p->tenSV << endl;
          cout << "LOP HOC: " << p->lop << endl;
          cout << "DIEM TONG KET: " << p->dtk << endl;
          if (p->dtk >=8)
               p->hk = "Tot";
          else
               if (p->dtk > 6.5)
                    p->hk = "Kha";
          cout << "HANH KIEM: " << p->hk << endl;
          cout <<"----------------------------------\n";
     }
}

void InputList (list first, list last, int n)
{
     SINHVIEN *p;
     p = first;
     int i = 1;
     while ((p->next != NULL) && (i <= n))
     {
          cout << "NHAP MA SINH VIEN: ";
          cin >> p->maSV;
          cin.ignore();
          cout << "\nNHAP TEN SINH VIEN: ";
          getline(cin, p->tenSV);
          cout << "\nNHAP LOP: ";
          getline(cin, p->lop);
          cout << "\nNHAP DIEM TONG KET: ";
          cin >> p->dtk;
          cin.ignore();          
     }
}