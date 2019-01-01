// Problem Link: https://www.codechef.com/JUNE17/problems/NEO01

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    long long int t,n,arr[100005],i,ans,sum,ta,ts;
    cin>>t;
    while(t--)
    {
        cin>>n;
        sum=0;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&arr[i]);
            sum+=arr[i];
        }
        ts=sum;
        ans=sum*n;
        sort(arr,arr+n);
        for(i=0;i<n;i++)
        {
            sum-=arr[i];
            ans=max(ans,(ts-sum)+(sum*(n-i-1)));
        }
        cout<<ans<<endl;
    }
    return 0;
}
