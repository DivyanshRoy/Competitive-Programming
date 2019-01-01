// Problem Link: https://www.codechef.com/MARCH17/problems/EXTRAN

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long int n,arr[100005],i;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        for(i=1;i<=n;i++)
            scanf("%ld",&arr[i]);
        sort(arr+1,arr+n+1);
        if((arr[2]-arr[1])!=1)
        {
            cout<<arr[1]<<endl;
            continue;
        }
        else if((arr[n]-arr[n-1])!=1)
        {
            cout<<arr[n]<<endl;
            continue;
        }
        for(i=1;i<n;i++)
        {
            if(arr[i]==arr[i+1])
            {
                cout<<arr[i]<<endl;
                break;
            }
        }
    }
    return 0;
}
