#include<iostream>
using namespace std;
int knapsack(int* wt, int* val, int n, int W){

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
     
  for(int i = 0;  i <= n; i++)
     delete [] dp[i];

     delete [] dp;

         return ans;
  
}

int main()
{
    
}