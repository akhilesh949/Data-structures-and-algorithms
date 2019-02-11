#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

ll alphacode(string a) 
{
	ll* output = new ll[a.length() + 1];
	output[0] = 1;
	output[1] = 1;

  for(int i = 2; i <= a.length(); i++)
  {
    output[i] = 0;
    
    if(a[i - 1] != '0')
     output[i] = output[i - 1];

     if((a[i - 2] - 48)*10 + (a[i - 1] - 48) <= 26 && (a[i - 2] - 48)*10 + (a[i - 1] - 48) >= 10)
       output[i] = (output[i - 2]%MOD + output[i]%MOD)%MOD;

  }  
	ll ans = output[a.length()];
  delete [] output;
  return ans;
}


int main()
{
  
  while(1)
  {
    string a;
    cin>>a;
    if(a[0] == '0')
     break;
    
    cout<<alphacode(a)<<endl;
  }
   
}