#include <iostream>

using namespace std;
void NhapMang(int a[], int n)
{
     for (int i = 0; i < n; i++)
     {
          cout << "a[" << i << "] = ";
          cin >> a[i];
     }
}
void insertionSort (int a[], int n)
{
     for (int i = 1; i < n; i++)
     {
          int key = a[i];
          int j = i - 1;
          while ((j >= 0) && (a[j] > key))
          {
               a[j + 1] = a[j];
               j--;
          }
          a[j + 1] = key;
     }
}
void XuatMang (int a[], int n)
{
     for (int i = 0; i < n; i++)
     {
          cout << a[i] << " ";
     }
}
void quickSort(int a[], int l, int r){
	int p = a[(l+r)/2];
	int i = l, j = r;
	while (i < j){
		while (a[i] < p){
			i++;
		}
		while (a[j] > p){
			j--;
		}
		if (i <= j){
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			i++;
			j--;
		}
	}
	if (i < r){
		quickSort(a, i, r);
	}
	if (l < j){
		quickSort(a, l, j);
	}
}
int main ()
{
     int a[100];
     int n; 
     cout << "Nhap so luong phan tu trong mang: ";
     cin >> n;
     cin.ignore();
     NhapMang(a, n);
     insertionSort(a, n);
     XuatMang(a, n);
}