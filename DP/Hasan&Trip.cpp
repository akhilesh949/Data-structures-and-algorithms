#include<iostream>
using namespace std;

class city 
{
    public:
    int x,y,fun;
};


int main()
{
    int n;
    cin >> n;
    city * arr = new city[n];

    for(int i = 0; i < n; i++)
      cin >> arr[i].x >> arr[i].y >> arr[i].fun;

      



}