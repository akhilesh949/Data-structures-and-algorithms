#include <bits/stdc++.h>
using namespace std;
int min_health(int **input, int m, int n)
{
  int **dp = new int*[m];
  for(int i = 0; i < m; i++)
   dp[i] = new int[n];

   dp[m - 1][n - 1] = 1;

    for(int i = m - 2; i >= 0; i--)
    {
      dp[i][n - 1] = dp[i + 1][n - 1] - input[i + 1][n - 1];
      
      if(dp[i][n - 1] <= 0)
        dp[i][n - 1] = 1;
    }
    for(int j = n - 2; j >= 0; j--)
    {
      dp[m - 1][j] = dp[m - 1][j + 1] - input[m - 1][j + 1];
      if(dp[m - 1][j] <= 0)
        dp[m - 1][j] = 1;
    }
    for(int i = m - 2; i >= 0; i--)
    {
     for(int j = n - 2; j >= 0; j--)
     {
       dp[i][j] = min(dp[i + 1][j] - input[i + 1][j], dp[i][j + 1] - input[i][j + 1]);
       if(dp[i][j] <= 0)
        dp[i][j] = 1;
     } 
    }

    int ans = dp[0][0];
    delete [] dp;
    return ans;

}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int m,n;
      cin>>m>>n;
      int**input = new int*[m];
      for(int i = 0; i < m; i++)
       input[i] = new int[n];

       for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
          cin>>input[i][j];
    
    cout<<min_health(input, m, n)<<endl;

  }
    return 0;
}
