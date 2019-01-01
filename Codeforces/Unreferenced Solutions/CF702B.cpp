#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    long int arr[n],i,j,cnt=0;
    long long int v;
    for(i=0;i<n;i++)
        scanf("%ld",&arr[i]);
    for(i=0;i<n;i++)
        for(j=i;j<n;j++)
        {
            if(i!=j)
            {
                v=arr[i]+arr[j];
                if(v && (v & -v) == v)
                    cnt++;
            }
        }
    cout<<cnt;
    return 0;
}
