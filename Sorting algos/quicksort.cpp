#include <iostream>
using namespace std;

int partition(int a[], int si, int ei)
{
    int p = a[si];
    int count = 0;
    for(int i = si + 1; i <= ei; i++)
    {
        if(a[i] <= p)
         count++;

    }
    a[si] = a[count + si];
    a[count + si] = p;   
    
    int i = si;
    int j = ei;
    while(i < si + count && j > si + count)
    {
        if(a[i] <= p)
          i++;

        else if(a[j] > p)
          j--;

          else
          {
              int temp = a[i];
              a[i] = a[j];
              a[j] = temp;
          }
            
    }
    return count + si;

}
void quickSortHelper(int a[], int si, int ei)
{
    if(si>=ei)
    return;
    int c = partition(a, si, ei);
    quickSortHelper(a, si, c - 1);
    quickSortHelper(a, c + 1, ei);


}
void quickSort(int a[], int n)
{
   quickSortHelper(a, 0, n - 1);
}
int main()
{
    int n;
    cin>>n;

    int a[100];
    for(int i = 0; i < n; i++)
       cin>>a[i];

       quickSort(a, n);

       for(int i = 0; i < n; i++)
        cout<<a[i]<<" ";
           
    
    return 0;
    
}