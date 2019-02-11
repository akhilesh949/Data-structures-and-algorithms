#include<iostream>
#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
int AdBC(int n, int k, int dp[101][100][2])
{ 
  dp[1][0][1] = 1;
  dp[1][0][0] = 1;
  
  for(int i = 2; i <= 100; i++)
   for(int j = 0; j < i; j++)
    {
        dp[i][j][0] = ((dp[i - 1][j][0])%MOD + (dp[i - 1][j][1])%MOD)%MOD;

        dp[i][j][1] = ((dp[i - 1][j - 1][1])%MOD + (dp[i - 1][j][0])%MOD)%MOD;


    }
  
    
}


int main()
{
    int t;
    cin>>t;
    int dp[101][100][2];

  memset(dp, 0, sizeof(dp));

    int ans = AdBC(100, 99, dp);
    while(t--)
    {
        int count, n, k;
        cin >> count >> n >> k;

        cout << count <<" " << (dp[n][k][0] + dp[n][k][1])%MOD << endl;
    }
}