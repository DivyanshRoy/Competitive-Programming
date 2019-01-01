#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    long long int t,k,i,arr[100005],a,b,pre[100005];
    arr[0]=1;
    cin>>t>>k;
    for(i=1;i<=100000;i++)
    {
        arr[i]=arr[i-1];
        if(i>=k)
            arr[i]=(arr[i]+arr[i-k])%mod;
    }
    pre[0]=0;
    for(i=1;i<=100000;i++)
        pre[i]=(pre[i-1]+arr[i])%mod;
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        cout<<(pre[b]-pre[a-1]+mod)%mod<<endl;
    }
    return 0;
}
