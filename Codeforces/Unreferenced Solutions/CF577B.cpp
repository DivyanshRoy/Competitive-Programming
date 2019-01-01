#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,m,i;
    long int arr[1001];
    cin>>n>>m;
    if(n>m)
    {
        cout<<"YES";
        return 0;
    }
    arr[0]=0;
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&arr[i]);
        arr[i]+=arr[i-1];
    }
    for(i=1;i<=n;i++)
    {
        if(arr[i]%m==0)
        {
            cout<<"YES";
            return 0;
        }
    }
    long int l,r;
    for(i=1;i<=n;i++)
    {
        for(l=1,r=l+i-1;r<=n;l++,r++)
        {
            if((arr[r]-arr[l-1])%m==0)
            {
                cout<<"YES";
                return 0;
            }
        }
    }
    cout<<"NO";
    return 0;
}
