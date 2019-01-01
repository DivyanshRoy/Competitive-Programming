#include<bits/stdc++.h>
using namespace std;

int main()
{
    char a;
    int b,m=2;
    cin>>a>>b;
    if(a!='a'&&a!='h')
        m++;
    if(b!=1&&b!=8)
        m++;
    if(m==2)
        cout<<3;
    else if(m==3)
        cout<<5;
    else
        cout<<8;
    return 0;
}
