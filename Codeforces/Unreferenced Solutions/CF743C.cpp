#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,x,y,z;
    cin>>n;
    if(n==1)
    {
        cout<<"-1";
        return 0;
    }
    x=n;
    y=n+1;
    z=x*y;
    cout<<x<<" "<<y<<" "<<z;
    return 0;
}
