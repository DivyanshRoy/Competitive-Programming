#include<bits/stdc++.h>
using namespace std;
long int arr[5000];
map< pair<long int, long int> ,long long int> store;

long long int dp(long int lb,long int len,long int m,long int k)
{
    if(lb+m*k>=len)
        return 0;
    if(!k)
        return 0;
    if(store.find(make_pair(lb,k))!=store.end())
    {
        return store[make_pair(lb,k)];
    }
    long long int sum=0,tsum,csum=0;
    long int i,j;
    tsum=0;
    for(j=lb;j<lb+m;j++)
    {
        tsum+=arr[j];
    }
    csum=dp(lb+m,len,m,k-1);
    sum=max(tsum+csum,sum);
    for(i=lb+1;i<len;i++)
    {
        tsum-=arr[i-1];
        tsum+=arr[i+m-1];
        csum=dp(i+m,len,m,k-1);
        sum=max(tsum+csum,sum);
    }
    store[make_pair(lb,k)]=sum;
    return sum;
}

int main()
{
    long int n,m,k,i,j;
    cin>>n>>m>>k;
    for(i=0;i<n;i++)
        scanf("%ld",&arr[i]);
    cout<<dp(0,n,m,k);
    return 0;
}
