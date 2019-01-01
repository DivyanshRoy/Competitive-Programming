// Problem Link: https://www.codechef.com/AUG17/problems/RAINBOWA

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,a[1000],i,state=0,l,r;
    bool b[8],f;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
            scanf("%d",&a[i]);
        l=1;
        r=n;
        f=0;
        for(i=0;i<8;i++)
            b[i]=0;
        while(l<=r)
        {
            if(a[l]!=a[r])
            {
                f=1;
                break;
            }
            else
            {
                b[a[l]]=1;
                l++;
                r--;
            }
        }
        for(i=1;i<=7;i++)
        {
            if(!b[i])
            {
                f=1;
                break;
            }
        }
        if(f)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    return 0;
}
