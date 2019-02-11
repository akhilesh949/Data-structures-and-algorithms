#include<iostream>
#include<climits>
#include<bits/stdc++.h>
using namespace std;
int knapsack(int* wt, int* val, int n, int W, int &sum){

  int** dp = new int*[n + 1];

    for(int i = 0; i <= n; i++)
     dp[i] = new int[W + 1];

     for(int i = 0; i <= W; i++)
      dp[0][i] = 0;

      for(int i = 0; i <= n; i++)
       dp[i][0] = 0;

       for(int i = 1; i <= n; i++)
         for(int w = 1; w <= W; w++)
         {
             dp[i][w] = dp[i - 1][w];
             if(wt[i - 1] <= w)
             {
                 dp[i][w] = max(dp[i - 1][w], val[i - 1] + dp[i - 1][w - wt[i - 1]]);
             }
         }
         int ans = dp[n][W];

         for(int i = 0; i <= W; i++)
         { 
             if(dp[n][i] == ans)
              {
                  sum = i;
                  break;
              }        
         }
     
  for(int i = 0;  i <= n; i++)
     delete [] dp[i];

     delete [] dp;

         return ans;
  
}

int main()
{
    int b,n;
    cin>>b>>n;

    while( b != 0 || n != 0)
   {
      
        int* fee = new int[n];
        int* fun = new int[n];

        for(int i = 0; i < n; i++)      
         {
             cin>>fee[i]>>fun[i];
         }
         int sum = 0;
        int ans = knapsack(fee, fun, n, b, sum);
           cout<< sum << " " << ans<< endl;
           
        cin>>b>>n;

    }
   }
