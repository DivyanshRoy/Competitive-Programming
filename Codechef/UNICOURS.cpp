// Problem Link: https://www.codechef.com/MAY17/problems/UNICOURS

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t,n,i,arr[100005],mx;
    cin>>t;
    while(t--)
    {
        cin>>n;
        mx=0;
        for(i=0;i<n;i++)
        {
            scanf("%ld",&arr[i]);
            mx=max(mx,arr[i]);
        }
        cout<<n-mx<<endl;
    }
    return 0;
}
