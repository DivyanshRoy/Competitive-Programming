// Problem Link: https://www.codechef.com/problems/MARBLES

#include<bits/stdc++.h>
using namespace std;

long long int C(long long int n,long long int r)
{
    long long int nr=n-r,i,ans=1;
    r=min(r,nr);
    nr=n-r;
    for(i=1;i<=r;i++)
    {
        ans=ans*(n-i+1)/(i);
    }
    return ans;
}

int main()
{
    long long int t,n,k;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        cout<<C(n-1,k-1)<<endl;
    }
    return 0;
}
