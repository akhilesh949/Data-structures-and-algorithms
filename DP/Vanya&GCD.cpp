#include<iostream>
#define MOD 1000000007

using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
     return a;

     else return gcd(b, a%b);

}

int Vanya(int *arr, int n)
{
    int **dp = new int*[n + 1];
    
    for(int i = 0; i <= n; i++)
     dp[i] = new int[101];

     for(int i = 0; i <= n; i++)
       dp[i][0] = 0;

     for(int i = 0; i <= n; i++)
      for(int k = 0; k < i; k++)
       {
           if(arr[k] < arr[i])
            {
                for(int g = 1; g <= 100; g++)
                 {
                     int ng = gcd(arr[i], g);
                     dp[i][ng] = ((dp[i][ng])%MOD + (dp[k][g])%MOD)%MOD;
                 }
            }
       }
       
     int sum = 0;
       for(int i = 0; i <= n; i++)
        sum = (sum%MOD + dp[i][1]%MOD)%MOD;

        return sum;

}

int main()
{
    int n;
    cin >> n;
    int *arr = new int[n];

    for(int i = 0; i < n; i++)
     cin >> arr[i]; 

     cout<<Vanya(arr, n);

}