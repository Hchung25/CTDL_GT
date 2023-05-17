#include <iostream>
#define MAX 100
using namespace std;


// Hàm nhập mảng
void Enter(int a[], int n)
{
     for (int i = 0; i < n; i++)
     {
          cout << "Arr[" << i << "] = ";
          cin >> a[i];
     }
}


// Thêm phần tử vào đầu mảng
void First_add_Element(int a[], int &n, int value)
{
     if (n == 0)
     {
          a[0] = value;
     }
     else
     {
          for (int i = n; i > 0; i--)
          {
               a[i] = a[i - 1];
               a[0] = value;
               n++;
          }
     }
}
// Thêm phần tử vào cuối mảng
void Last_add_Element(int a[], int &n, int value)
{
     if (n == 0)
          a[0] = value;
     else 
          a[n] = value;
}

// Thêm phần tử vào vị trí locate của mảng
void addElement(int a[], int &n, int value, int locate)
{
     if (n >= MAX)  
          return;
     if (locate < 0)
          First_add_Element(a, n, value);
     else if (locate > n)
               Last_add_Element(a, n, value);
     for (int i = n; i > locate; i--)
     {
          a[i] = a[i - 1];
     }
     a[locate] = value;
     ++n;
}


// Duyệt mảng
void disPlay(int a[], int n)
{
     for (int i = 0; i < n; i++)
     {
          cout << a[i] << " ";
     }
}


// Tìm giá trị lớn nhất trong mảng
int maxArr(int a[], int n)
{
     int max = a[0];
     for (int i = 1; i < n; i++)
     {
          if (a[i] > max)
               max = a[i];
     }
     return max;
}

// Tìm vị trí của giá trị lớn nhất trong mảng

int pos_maxArr(int a[], int n)
{
     // Special case
     if (n == 0) return -1;
     int pos = 0;
     for (int i = 0; i < n; i++)
     {
          if (a[i] > a[pos])
               pos = i;
     }
     return pos;

}

// Xóa phần tử cuối mảng
void last_Del(int a[], int &n)
{
     if (n > 0)
          n--;
}
// Xóa phần tử đầu mảng
void first_Del(int a[], int &n)
{
     if (n == 0) return;
     for (int i = 1; i < n; i++)
     {
          a[i - 1] = a[i];
     }
     n--;
}

/*
     Xóa giá trị tại vị trí bất kỳ
     - Tìm vị trí của giá trị cần xóa 
          func Find(int a[], int n, int value);
     - Xóa giá trị có vị trí tìm được trong mảng
*/

int Find(int a[], int n, int value)
{
     if (n == 0) return 0;
     for (int i = 0; i < n; i++)
     {
          if (a[i] == value)
               return i;
     }
     return -1;
}
void delValue(int a[], int &n, int value)
{
     if (n == 0) return;
     int pos = Find(a, n, value);
     if ((pos < 0) || (pos > n - 1)) return;
     for (int i = pos + 1; i < n; i++)
     {
          a[i - 1] = a[i];
     }
     n--;
}
// Sắp xếp
void sortArr (int a[], int n)
{
     for (int i = 0; i < n; i++)
          for (int j = i + 1; j < n; j++)
          {
               if (a[i] > a[j])
               {
                    int tmp = a[i];
                    a[i] = a[j];
                    a[j] = tmp;
               }
          }
}

// MAIN
int main()
{
     // Tạo mới 1 mảng
     int arr[MAX];
     int n; 
     cout << "Enter the length of arr: ";
     cin >> n;
     // Nhập giá trị cho mảng
     Enter(arr, n);
     
     /*
     Thêm phần tử cho mảng
     - Thêm đầu
     - Thêm cuối
     - Thêm giữa bất kỳ
     */
     //     int value = 100, locate = 3;
     //     cin.ignore();
     //     addElement(arr, n, value, locate);
     //     disPlay(arr, n);

     // Tìm giá trị lớn nhất trong mảng
      // cout << "Max value of intArr: " << maxArr(arr, n);
     
     // Tìm vị trí của GTLN
      //cout << "Position of max value: " << pos_maxArr(arr, n);
     

     // Xóa phần tử trong mảng
     // Xóa cuối
      // last_Del(arr, n);

     // Xóa đầu
      // first_Del(arr, n);
     
     // Xóa có vị trí
     /* int value;
     cout << "Value: "; cin >> value;
     delValue(arr, n, value);
     disPlay(arr, n);
     */
     // Sắp xếp giá trị mảng
     sortArr(arr, n);
     disPlay(arr, n);
}


/*
Các thao tác cơ bản trên mảng 1 chiều
- Tạo mới 1 mảng
- Thêm phần tử 
- Loại bỏ phần tử
- Tìm kiếm
-   Sắp xếp
- Duyệt ds mảng
*/