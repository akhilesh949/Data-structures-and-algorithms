#include<iostream>
using namespace std;

int Kadane(int *a, int n)
{
    int curr_sum = 0; 
    int best_sum = 0;

    for(int i = 0; i < n; i++)
    {
        curr_sum += a[i];
        if(curr_sum > best_sum)
         best_sum = curr_sum;

         if(curr_sum < 0)
          curr_sum = 0;
    }
    return best_sum;
}

int MaxSumR(int **input, int m, int new)
{
    int best = INT_MIN;
  int *arr = new int[n];
   for(int i = 0; i < n; i++)
    arr[i] = 0;

  for(int l = 0; l < m - 1; l++)
    for(int r = l ; r < m; r++)
     {
       for(int i = 0; i < n; i++)
        {
            arr[i] += input[i][r];
            int ans = Kadane(arr, n);
            if(ans > best)
             best = ans;
        }
     }
    delete [] arr;
    return best;
}

int main()
{
    int m,n;
    cin>>m>>n;
     
    int**input = new int*[m];
    for(int i = 0; i < m; i++)
     input[i] = new int[n];

    for(int i = 0; i < m; i++)
    for(int j = 0; j < n; j++)
     cin>>input[i][j];

     cout<<MaxSumR(int **input, int m, int n);

     
}