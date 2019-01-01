#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,x,i,j;
    cin>>n>>x;
    long int arr[n],cnt=0;
    for(i=0;i<n;i++)
        scanf("%ld",&arr[i]);
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if((arr[i]^arr[j])==x)
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
