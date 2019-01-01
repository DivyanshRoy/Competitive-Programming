// Problem Link: https://www.codechef.com/JUNE17/problems/XENRANK

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    long long int t,u,v;
    cin>>t;
    while(t--)
    {
        cin>>u>>v;
        cout<<1+u+((u+v)*(u+v+1))/2<<endl;
    }
    return 0;
}
