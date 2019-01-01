#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,i,cnt=2,left;
    cin>>n;
    long int x[n],h[n];
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld",&x[i],&h[i]);
    }
    if(n==1)
    {
        cout<<1;
        return 0;
    }
    left=x[0];
    for(i=1;i<n-1;i++)
    {
        if((x[i]-left)>h[i])
        {
            cnt++;
            left=x[i];
        }
        else if((x[i+1]-x[i])>h[i])
        {
            cnt++;
            left=x[i]+h[i];
        }
        else
            left=x[i];
    }
    cout<<cnt;
    return 0;
}
