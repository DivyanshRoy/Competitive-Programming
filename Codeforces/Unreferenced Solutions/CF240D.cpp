#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int arr[2001][2001];

int main()
{
    long long int n,k,i,j,l,ans=0;
    cin>>n>>k;
    for(i=1;i<=k;i++)
    {
        for(j=1;j<=n;j++)
            arr[i][j]=0;
    }
    arr[0][1]=1;
    for(i=0;i<k;i++)
    {
        for(j=1;j<=n;j++)
        {
            for(l=j;l<=n;l+=j)
                arr[i+1][l]=(arr[i+1][l]+arr[i][j])%mod;
        }
    }
    for(i=1;i<=n;i++)
    {
        ans=(ans+arr[k][i])%mod;
    }
    cout<<ans;
    return 0;
}
