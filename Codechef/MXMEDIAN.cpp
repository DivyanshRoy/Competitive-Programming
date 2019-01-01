// Problem Link: https://www.codechef.com/MAY17/problems/MXMEDIAN

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t,n,i,arr[100005],ans,aa[100005],ind;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=0;i<2*n;i++)
            scanf("%ld",&arr[i]);
        sort(arr,arr+2*n);
        ans=arr[((n+1)/2)+(n-1)];
        cout<<ans<<endl;
        ind=0,i=0;
        while(ind<2*n)
        {
            aa[ind]=arr[i];
            i++;
            ind+=2;
        }
        ind=1;
        while(ind<2*n)
        {
            aa[ind]=arr[i];
            i++;
            ind+=2;
        }
        for(i=0;i<2*n;i++)
            cout<<aa[i]<<" ";
        cout<<endl;
    }
    return 0;
}
