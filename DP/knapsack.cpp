#include<iostream>
using namespace std;
int knapsack(int *wt, int *val, int n, int W)
{
    int** dp = new int[n + 1];

    for(int i = 0; i <= n; i++)
     dp[i] = new int[W + 1];

     for(int i = 0; i <= n; i++)
      dp[0][i] = 0;

      for(int i = 0; i <= W; i++)
       dp[i][0] = 0;

       for(int i = 1; i <= n; i++)
         for(int w = 1; w <= W; w++)
         {
             dp[w][i] = dp[w][i - 1];
             if(wt[i - 1] <= W)
             {
                 dp[w][i] = max(dp[w][i], val[i - 1] + dp[W - w][i - 1]);
             }
         }
         ans = dp[W][i];
         return ans;
}
int main()
{
    
}