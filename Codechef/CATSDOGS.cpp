// Problem Link: https://www.codechef.com/JAN17/problems/CATSDOGS

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,c,d,l,rc;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld %lld",&c,&d,&l);
        if(l%4!=0)
        {
            cout<<"no\n";
            continue;
        }
        if(l>(c+d)*4)
        {
            cout<<"no\n";
            continue;
        }
        rc=c-2*d;
        if(rc>=0)
        {
            if(l<(d+rc)*4)
            {
                cout<<"no\n";
                continue;
            }
        }
        else
        {
            if(l<d*4)
            {
                cout<<"no\n";
                continue;
            }
        }
        cout<<"yes\n";
    }
    return 0;
}
