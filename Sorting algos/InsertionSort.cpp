#include<iostream>
using namespace std;

//recall card example

void InsertionSort(int a[], int n)
{
    for(int i = 1; i < n; i++)
     for(int j = 0; j < i; j++)
      {
          if(a[j] > a[i])
          {
              int temp = a[j];
              a[j] = a[i];
              a[i] = temp;
          }
      }
}
int main()
{
    int n;
    cin >> n;
    int *a = new int[n];
    for(int i = 0; i < n; i++)
     cin >> a[i];

     InsertionSort(a, n);

     for(int i = 0; i < n; i++)
      cout << a[i] <<" ";
}




