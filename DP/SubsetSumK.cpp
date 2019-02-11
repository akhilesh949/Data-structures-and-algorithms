#include<iostream>
using namespace std;
void Subk(int* arr, int n, int k)
{
    bool** dp = new bool*[2];
    for(int i = 0; i <= 1; i++)
     dp[i] = new bool[k + 1];
    
    dp[0][0] = 1;

    int flag = 1;
    
    for(int i = 1; i <= k; i++)
      dp[0][i] = 0;


     for(int i = 1; i <= n; i++) 
      {
          for(int j = 1; j <= k; j++)
             {
                  dp[flag][j] = dp[flag ^ 1][j];
                  
                    if(arr[i - 1] <= j)
                    {
                        dp[flag][j] = (dp[flag][j] || dp[flag ^ 1][j - arr[i - 1]]);
                    }
            

             }
           flag = flag ^ 1;

     }
       if(dp[flag ^ 1][k] == 1)
        cout<<"Yes";
       
        else cout<<"No";

      for(int i = 1; i <= 1; i++)
           delete [] dp[i];
       
       delete [] dp;

}
int main()
{
    int n,k;
    cin >> n;
    int* arr = new int[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cin >> k;

  Subk(arr, n, k);
}
