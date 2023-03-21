#include <iostream>

using namespace std;

struct element
{
     int data;
     element *next;
};

typedef element *list;
list first, last;

void KhoiTao(list &first, list &last)
{
     first = NULL;
     last = NULL;
}

element * TaoPhanTu(int x)
{
     element *p;
     p = new(element);
     if (p != NULL)
     {
          cout << "Memory Allocated!";
     }else{
          cout << "Bad Allocated!";
          return;
     }
     p->data = x;
     p->next = NULL;
     return p;
}

void ThemDau(list &first, list &last, element * p)
{
     p->next = first;
     first = p;
     if (last = NULL)
          last = p;
}

void ThemCuoi(list &first, list &last, element * p)
{
     if (first == NULL)
     {
          first = p;
          last = p;
     }else
     {
          last->next = p;
          last = p;
     }
}

void InDS (list first, list last)
{
     element * p;
     p = first;
     while(p != NULL)
     {
          cout << p->data << " ";
          p = p->next;
     }
}

// Tìm phần tử 
element * TimPhanTu (list first, list last, int k)
{
     element * p;
     p = first;
     while(p != NULL)
     {
          if (p->data == k)
               return p;
          p = p->next;
     }
     return NULL;
}

// Xóa phần tử

void XoaDau (list &first, list &last)
{
     if(first == NULL) return;
     if(first->next == NULL)
     {
          element * p;
          p = first;
          first = NULL;
          last = NULL;
          delete p;
     }
     else{
          element * p;
          p = first;
          first = first->next;
          delete p;
     }
}

void XoaCuoi(list &first, list &last)
{
     if(first == NULL) return;
     if(first->next == NULL)
     {
          element * p;
          p = first;
          first = first->next;
          delete p;
     }
     else
     {
          element * p;
          p = first;
          while((p->next) != last)
               p = p->next;
          last = p;
          p = last;
          last->next = NULL;
          delete p;
     }
}
element *TimTruoc (list first, list last, int k)
{
     element * p;
     p = first;
     while((p->next)->data != k && (p->next) != NULL)
          p = p->next;
     return p;
}
void Xoa (list &first, list &last, int k)
{
     if (first == NULL) return;
     if (first->data == k) XoaDau(first, last);
     else
     {
          element * p, *q;
          p = TimTruoc(first, last, k);
          if (p->next == last) return;
          q = p->next;
          p->next = q->next;
          if (q == last) 
               last = p;
          delete q;
     }
}

// Them Giua danh sach
element * TimTruocVT(list first, list last, element *t)
{
     element * p;
     p = first;
     while((p->next)->data < t->data || (p->next)->data != NULL)
     {
          p = p->next;
     }
}
void ThemGiua(list &first, list last, element * t)
{
     if ((first == NULL) || (first->data > t->data))
          ThemDau(first, last, t);
     else
     {
          element * p;
          p = TimTruocVT(first, last, t);
          t->next = p->next;
          p->next = t;
          if (t->next == NULL)
               last = t;
     }
}