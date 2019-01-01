#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,a,b;
    cin>>n>>a>>b;
    a=a+b;
    a=a%n;
    a+=n;
    a%=n;
    if(a==0)
        cout<<n;
    else
        cout<<a%n;
    return 0;
}
