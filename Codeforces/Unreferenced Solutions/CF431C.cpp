#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    long long int n,k,d,i,a[101],b[101],j;
    cin>>n>>k>>d;
    for(i=1;i<=n;i++)
        a[i]=b[i]=0;
    a[0]=1;
    b[0]=0;
    for(i=0;i<n;i++)
    {
        for(j=1;j<d;j++)
        {
            if(i+j>n)
                break;
            a[i+j]=(a[i+j]+a[i])%mod;
            b[i+j]=(b[i+j]+b[i])%mod;
        }
        for(j=d;j<=k;j++)
        {
            if(i+j>n)
                break;
            b[i+j]=(b[i+j]+a[i])%mod;
            b[i+j]=(b[i+j]+b[i])%mod;
        }
    }
    cout<<b[n];
    return 0;
}
