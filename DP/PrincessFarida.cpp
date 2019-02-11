#include <bits/stdc++.h>
using namespace std;

long long Farida(long long *input, long long n)
{
  long long * output = new long long[n];
   output[0] = input[0];
   output[1] = max(input[0], input[1]);
     for (long long i = 2; i < n; i++)
   { 
     output[i] = max(output[i - 2] + input[i], output[i - 1]);

   }
   long long ans = output[n - 1];
   delete [] output;
   return ans;

}

long long main()
{
   long long t;
   cin>>t;
   long long a = 1;
   while(t--)
   {
       long long n;
       cin>>n;
       long long *input = new long long[n];
       for(long long i = 0; i < n; i++)
         cin>>input[i];
   
    cout<<"Case "<<a<<": "<<Farida(input, n)<<endl;
    a++;
    delete [] input;
   }

    return 0;
}
