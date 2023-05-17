#include <iostream>

using namespace std;

struct Element
{
     int data;
     Element *next, *pre;
};

typedef Element *list;
list first, last;

/*
Các hàm thêm
- Thêm đầu, thêm cuối, thêm giữa
*/

void ThemDau (list &first, list &last, Element *p)
{
     if (first == NULL)
     {
          first = p;
          last = p;
     }
     else{
          p->next = first;
          first->pre = p;
          first = p;
     }
}

void ThemCuoi (list &first, list &last, Element *p)
{
     if (first == NULL)
     {
          first = p;
          last = p;
     }
     else{
          last->next = p;
          p->pre = last;
          last = p;
     }
}

void Them (list &first, list &last, Element * t)
{
     if (first == NULL)
     {
          first = t;
          last = t;
     }
     else{
          Element *p = first;
          while ((p->next != NULL) && (p->data < t->data))
          {
               p = p->next;
          }
          if (p == first)
          {
               t->next = first;
               first->pre = t;
               first = t;
          }else{
               if (p == NULL)
               {
                    last->next = t;
                    t->pre = last;
                    last = t;
               }else{
                    t->next = p;
                    t->pre = p->pre;
                    p->pre = t;
                    (t->pre)->next = t;
               }
          }
     }
}

void XoaDau (list &first, list &last)
{
     Element * p;
     p = first;
     if (p == NULL) return;
     if (p->next == NULL)
     {
          first = NULL;
          last = NULL;
          delete p;
     }else{
          first = first->next;
          first->pre = NULL;
          delete p;
     }
}

void XoaCuoi (list &first, list &last)
{
     if (first == NULL) return;
     if (first->next == NULL)
     {
          Element *p;
          p = first;
          first->next = NULL;
          first->pre = NULL;
          delete p;
     }
     else{
          Element * p;
          p = last;
          last = last->pre;
          last->next = NULL;
          delete p;
     }
}

Element * TimVT(list first, list last, int k)
{
     Element *p;
     p = first;
     while (p != NULL)
     {
          /* code */
          if ((p->data) == k)
               return p;
          p = p->next;
     }
}
void Xoa (list &first, list &last, int k)
{
     Element *p;
     p = TimVT(first, last, k);
     if(p == NULL) return;
     if (p->next = NULL) XoaDau(first, last);
     else{
          if (p = last) XoaCuoi(first, last);
          else{
               Element *q, *e;
               p->next = e;
               p->pre = q;
               q->next = e;
               e->pre = q;
               delete p;
          }
     }
}