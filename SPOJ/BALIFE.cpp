// Problem Link: https://www.spoj.com/problems/BALIFE/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long long int n,arr[9001],i,pre[9001],ans,l,aim;
    while(1)
    {
        cin>>n;
        if(n==-1)
            break;
        pre[0]=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            pre[i]=pre[i-1]+arr[i];
        }
        if(pre[n]%n!=0)
        {
            cout<<-1<<endl;
            continue;
        }
        ans=0;
        aim=pre[n]/n;
        for(i=1;i<n;i++)
        {
            l=abs(pre[i]-aim*i);
            ans=max(ans,l);
        }
        cout<<ans<<endl;
    }
    return 0;
}