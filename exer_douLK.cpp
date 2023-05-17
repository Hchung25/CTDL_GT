#include <iostream>

using namespace std;

struct INT
{
     int data;
     INT *next;
};
typedef INT *list;
list first, last;

void KhoiTao (list first, list last)
{
     first = NULL;
     last = NULL;
}

INT * TaoPhanTu (int x)
{
     INT * p;
     p = new(INT);
     if (p == NULL)
     {
          cout << "Cap phat that bai!";
          return NULL;
     }
     else{
          p->data = x;
          p->next = NULL;
          return p;
     }
}
void ThemDau (list &first, list &last, INT *p)
{
     if (first == NULL) return;
     else{
          p->next = first;
          first = p;
     }
}

void ThemCuoi (list &first, list &last, INT *p)
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
INT *timtruocVT(list first, list last, INT *t)
{
     INT * p;
     p = first;
     while (((p->next) != NULL) && (((p->next)->data) < (t->data)))
          p = p->next;
     return p;
}
void ThemGiua (list &first, list &last, INT *t)
{
     if ((first == NULL) || (first->data < t->data))
          ThemDau(first, last, t);
     else{
          INT *p;
          p = timtruocVT(first, last, t);
          t->next = p->next;
          p->next = t;
          if ((t->next) == NULL)
               last = t;
     }
}

void XoaDau (list &first, list &last)
{
     if (first == NULL) return;
     if (first->next == NULL)
     {
          INT *p;
          p = first;
          first = NULL;
          last = NULL;
          delete p;
     }
     else{
          INT * p;
          p = first;
          first = first->next;
          delete p;
     }
}

void XoaCuoi (list &first, list &last)
{
     if (first == NULL) return;
     if (first->next == NULL)
     {
          INT *p;
          p = first;
          first = NULL;
          last = NULL;
          delete p;
     }
     else{
          INT *p;
          p = first;
          while ((p->next) != last)
          {
               p = p->next;
          }
          last = p;
          p = last;
          last->next = NULL;
          delete p;
     }
}
INT *timK(list first, list last, int k)
{
     INT * p;
     p = first;
     while ((((p->next)->data) == k) && ((p->next) != NULL))
          p = p->next;
     return p;
}
void XoaViTri (list &first, list &last, int k)
{
     if (first == NULL) return;
     if ((first->data) == k)
          XoaDau(first, last);
     else{
          INT *p;
          p = timK(first, last, k);
          INT * q;
          if (q == last) return;
          q = p->next;
          p->next = q->next;
          if (q == last) last = p;
          delete q;
     }
}

void DuyetDS (list first, list last)
{
     INT *p;
     p = first;
     while ((p->next) != NULL)
     {
          cout << p->data << " ";
          p = p->next;
     }
}


int main ()
{
     KhoiTao(first, last);
     INT * p;
     int element;
     cout << "Nhap phan tu: ";
     cin >> element;
     p = TaoPhanTu(element);
     ThemDau(first, last, p);
     DuyetDS(first, last);
}