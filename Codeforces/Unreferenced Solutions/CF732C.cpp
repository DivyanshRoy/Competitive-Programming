#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int b,d,s,m,c=0;
    cin>>b>>d>>s;
    m=max(b,max(d,s));
    if(d!=m)
    {
        c+=(m-1-d);
    }
    if(b!=m)
    {
        c+=(m-1-b);
    }
    if(s!=m)
    {
        c+=(m-1-s);
    }
    cout<<c;
    return 0;
}
