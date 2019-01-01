// Problem Link: https://www.codechef.com/problems/COINS

#include<bits/stdc++.h>
using namespace std;

map<long long int,long long int> ma;

long long int f(long long int n)
{
    if(ma.find(n)!=ma.end())
        return ma[n];
    long long int ans=0;
    if(n<((n/2)+(n/3)+(n/4)))
    {
        ans+=f(n/2);
        ans+=f(n/3);
        ans+=f(n/4);
    }
    else
    {
        ans+=n;
    }
    return ma[n]=ans;
}

int main()
{
    long long int t,n;
    while(cin>>n!='\0')
    {
        cout<<f(n)<<endl;
    }
    return 0;
}
