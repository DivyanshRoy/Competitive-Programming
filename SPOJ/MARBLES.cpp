// Problem Link: https://www.spoj.com/problems/MARBLES/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int t,n,r,nr,ans,i;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld",&n,&r);
        n--;
        r--;
        nr=n-r;
        r=min(r,nr);
        ans=1;
        nr=n-r;
        nr++;
        for(i=1;i<=r;i++)
        {
            ans=(ans*nr)/i;
            nr++;
        }
        cout<<ans<<endl;
    }
    return 0;
}