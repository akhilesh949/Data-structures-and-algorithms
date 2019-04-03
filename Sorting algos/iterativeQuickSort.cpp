#include<iostream>
#include<stack>
using namespace std;
int quick(int *arr, int n, int beg, int end)
{
    int left = beg;
    int right = end;
    int loc = left;

   while(1)
   { 
    while(arr[loc] <= arr[right] && loc != right)
     right = right - 1;
 
     if(loc == right)
      break;       
     
      if(arr[loc] > arr[right])
      {
         int temp = arr[loc];
         arr[loc] = arr[right];
         arr[right] = temp;
         loc = right;
      }
      while(arr[loc] >= arr[left] && loc != left)
       left = left + 1;
        
        if(loc == left)
         break;

       if(arr[loc] < arr[left])
       {
         int temp = arr[loc];
         arr[loc] = arr[left];
         arr[left] = temp;
         loc = left;
       }
  }
  return loc;
     
}
void quickSort(int *arr, int n)
{
    if(n == 1 || n == 0)
     return;

   stack<int> upper;
   stack<int> lower;

   lower.push(0);
   upper.push(n - 1);
   
   while(!upper.empty() && !lower.empty())
   {
       int beg = lower.top();
       int end = upper.top();
       lower.pop();
       upper.pop();
       int loc = quick( arr, n, beg, end);
       if(beg <= loc - 1)
       {
           lower.push(beg);
           upper.push(loc - 1);
       }
       if(end >= loc + 1)

       {
           lower.push(loc + 1);
           upper.push(end);
       }
       
   }
}
int main()
{
    int n;
    cin>>n;
    int *arr = new int[n];
    for(int i = 0; i < n; i++)
      cin >> arr[i];
    
    quickSort( arr, n);
    for(int i = 0; i < n; i++)
     cout<<arr[i]<<" ";
   

}