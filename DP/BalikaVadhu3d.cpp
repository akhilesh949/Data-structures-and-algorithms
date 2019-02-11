#include<iostream>
#include<string>
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int lcs(string s1, string s2)
{
    int m = s1.length();
    int n = s2.length();
    int **dp = new int*[m + 1];
    
    for(int i = 0; i <= m; i++)
     dp[i] = new int[n + 1];
    
    for(int i = 0; i <= n; i++)
     dp[0][i] = 0;

     for(int j = 0; j <= m; j++)
      dp[j][0] = 0;
     
      for(int i = 1; i <= m; i++)
       for(int j = 1; j <= n; j++)
       {
           if(s1[m - i] == s2[n - j])
             dp[i][j] = 1 + dp[i - 1][j - 1];
             
             else
             dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
             
       }

       int ans = dp[m][n];

       for(int i = 0; i <= m; i++)
        delete [] dp[i];

        delete [] dp;
    
     return ans;



}


int balikavadhu(string s1, string s2, int k)
{
  if(lcs(s1,s2) < k)
    return 0;
  
    int m = s1.length();
    int n = s2.length();

    int ***dp = new int**[m + 1];

    for(int i = 0; i <= m; i++)
     {
         dp[i] = new int*[n + 1];
         for(int j = 0; j <= n; j++)
         dp[i][j] = new int[k + 1];
     }

     // if k == 0, then we return 0
     for(int i = 0; i <= m; i++)
      for(int j = 0; j <= n; j++)
      {
          dp[i][j][0] = 0;
      }

      for(int i = 0; i <= m; i++)
       for(int j = 0; j <= k; j++)
       {
           dp[i][0][j] = 0;
       }

       for(int i = 0; i <= n; i++)
        for(int j = 0; j <= k; j++)
        {
           dp[0][i][j] = 0;
        }
        
        for(int i = 1; i <= m; i++)
         for(int j = 1; j <= n; j++)
          for(int r = 1; r <= k; r++)
          {
              if(s1[m - i] == s2[n - j])
              {
                  dp[i][j][r] = max(s1[m - i] + dp[i - 1][j - 1][r - 1], max(dp[i - 1][j][r], dp[i][j - 1][r]));
              }
              else
              {
                  dp[i][j][r] = max(dp[i - 1][j][r], dp[i][j - 1][r]);
              }
          }

          int ans = dp[m][n][k];
          for(int i = 0; i <= m; i++)
           for(int j = 0; j <= n; j++)
            {
                delete [] dp[i][j];
            }

            for(int i = 0; i <= m; i++)
             delete [] dp[i];

             delete [] dp;

             return ans;



}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
   string s1,s2;
   cin>>s1>>s2;
   int k;
   cin>>k;
  
   cout<<balikavadhu(s1,s2,k)<<endl;
  }
}