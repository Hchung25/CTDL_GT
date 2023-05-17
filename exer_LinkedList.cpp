#include <iostream>

using namespace std;

struct element
{
     int data;
     element * next;
};
typedef element * list;
list first, last;

void KhoiTao(list &first, list &last)
{
     first = NULL;
     last = NULL;
}

// Tạo phần tử
element * TaoPhanTu (int value)
{
     element * p;
     p = new(element);
     if (p == NULL)
     {
          cout << "";
          return;
     }
     p->data = value;
     p->next = NULL;
     return p;
}

// Thêm đầu
void ThemDau (list &first, list &last, element *p)
{
     p->next = first;
     first = p;
     if (last == NULL)
          last = p;
}

// Thêm cuối
void ThemCuoi (list &first, list &last, element * p)
{
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

// Duyệt danh sách
void InDS (list first, list last)
{
     element * p;
     p = first;
     while (p != NULL)
     {
          cout << p->data;
          p = p->next;
     }
}

// Tìm phần tử trong danh sách liên kết
element * TimPhanTu (list first, list last, int k)
{
     element * p;
     p = first;
     while (p != NULL)
     {
          if (p->data == k)
               return p;
          p = p -> next;     
     }
     return NULL;
}

// Xóa phần tử trong Linked List

void XoaDau (list &first, list &last)
{
     element * p;
     if (first ->next == NULL)
     {
          p = first;
          first = NULL;
          last = NULL;
          delete p;
     }
     else{
          p = first;
          first = first -> next;
          delete p;
     }
}

void XoaCuoi (list &first, list &last)
{
     if (first == NULL) return;
     if (first -> next = NULL)
     {
          element * p;
          p = first;
          first = NULL;
          last = NULL;
          delete p;
     }
     else
     {
          element * p;
          p = first;
          while ((p->next) != last)
               p = p->next;
          last = p;
          p = last;
          last ->next = NULL;
          delete p;
     }
}
// Xóa ở vị trí có giá trị là k
void Xoa (list &first, list &last, int k)
{
     if (first == NULL) return;
     if (first->data == k) XoaDau(first, last);
     else
     {
          element *p, *q;
          p = timtruocK(first, last, k);
          q = p->next;
          p->next = q->next;
          delete q;

     }
}
// Tìm trước vị trí k

element * timtruocK (list first, list last, int k)
{
     element * p;
     p = first;
     while (((p->next)->data != k) && (p->next != NULL))
          p = p->next;
     return p;
}

// Thêm giữa danh sách liên kết 
     // Hàm tìm trước vị trí t
element * TimTruoc (list first, list last, element * t)
{
     element * p;
     p = first;
     while ((p->next != NULL) && ((p->next)->data) > (t->data))
          p = p->next;
     return p;
}
void Them (list &first, list &last, element * t)
{
     if ((first == NULL) || (first->data > t->data))
          ThemDau(first, last, t);
          else{
               element *p;
               p = TimTruoc(first, last, t);
               t->next = p->next;
               p->next = t;
               if (t->next == NULL)
                    last = t;
          }
}

// Sắp xếp 
void Sort (list first, list last)
{
     element * p;
     p = first;
     while (p != NULL)
     {
          element * q;
          q = p->next;
          while (q != NULL)
          {
               if ((p->data) > (q->data))
               {
                    int tmp = p->data;
                    p->data = q->data;
                    q->data = tmp;
               }
          }
          p = p->next;
     }
}
int main()
{

}