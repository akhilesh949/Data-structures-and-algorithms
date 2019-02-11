#include<iostream>
#include<cstring>
using namespace std;

int fibMemoization(int n, int *arr)
{
    if(n == 1 || n == 0)
     return 1;

     if(arr[n] > 0)
       return arr[n];

    int output = fibMemoization(n - 1, arr) + fibMemoization(n - 2, arr);
    arr[n] = output;

       return output;
}
int fibDP(int n)
{
  int *arr = new int[n + 1];
  arr[0] = 1;
  arr[1] = 1;

  for(int i = 2; i <= n; i++)
  {
      arr[i] = arr[i - 1] + arr[i - 2];
  }
  int ans = arr[n];
  delete [] arr;
  return ans;

}
int main()
{
   int n;
   cin>>n;
   int *arr = new int[n + 1];
   for(int i = 0; i <=n; i++)
    arr[i] = 0;
   
   cout<<fibMemoization(n, arr)<<endl;
   cout<<fibDP(n);


}
