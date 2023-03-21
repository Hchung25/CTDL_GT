#include <iostream>

using namespace std;

struct element
{
     int data;
     element *next;
};

typedef element *list;
list first, last;

void CreateList (list &first, list &last)
{
     first = NULL;
     last = NULL;
}
element *TaoPhanTu (int x)
{
     element *p;
     p = new(element);
     p->data = x;
     p->next = NULL;
     return p;
}
void ThemDau (list &first, list &last, element *p)
{
     p->next = first;
     first = p;
     if(last = NULL)
     {
          last = p;
     }
}

void ThemCuoi (list &first, list &last, element *p)
{
     if(first == NULL)
     {
          first = p;
          last = p;
     }
     else{
          last->next = p;
          last = p;
     }
}
// InDanhSach

void InDS (list first, list last)
{
     element *p;
     p = first;
     while(p != NULL)
     {
          cout << p->data;
          p = p->next;
     }
}

int main()
{
     CreateList(first, last);
     element *p;
     p = TaoPhanTu(5);
     ThemDau(first, last, p);
     InDS(first, last);
     return 0;
}