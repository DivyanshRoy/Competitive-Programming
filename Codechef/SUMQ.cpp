// Problem Link: https://www.codechef.com/JUNE17/problems/SUMQ

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    long long int t,p,q,r,ap[100005],aq[100005],ar[100005],i,j,k,pp[100005],pq[100005],pr[100005],ans;
    cin>>t;
    while(t--)
    {
        cin>>p>>q>>r;
        for(i=1;i<=p;i++)
            scanf("%lld",&ap[i]);
        for(i=1;i<=q;i++)
            scanf("%lld",&aq[i]);
        for(i=1;i<=r;i++)
            scanf("%lld",&ar[i]);
        
        ap[p+1]=mod;
        ar[r+1]=mod;
        sort(ap+1,ap+p+2);
        sort(ar+1,ar+r+2);
        pp[0]=pq[0]=pr[0]=0;
        for(i=1;i<=p;i++)
            pp[i]=(pp[i-1]+ap[i])%mod;
        for(i=1;i<=r;i++)
            pr[i]=(pr[i-1]+ar[i])%mod;
        ans=0;
        for(j=1;j<=q;j++)
        {
            i=(long long int)(upper_bound(ap+1,ap+p+2,aq[j])-ap);
            k=(long long int)(upper_bound(ar+1,ar+r+2,aq[j])-ar);
            long long int f,s;
            f=(pp[i-1]+((i-1)*aq[j])%mod)%mod;
            s=(pr[k-1]+((k-1)*aq[j])%mod)%mod;
            ans=(ans+(f*s)%mod)%mod;
        }
        cout<<ans<<endl;
    }
    return 0;
}
