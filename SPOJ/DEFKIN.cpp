// Problem Link: https://www.spoj.com/problems/DEFKIN/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long int t,n,w,h,r[40009],c[40009],i,wm,hm;
    cin>>t;
    while(t--)
    {
        cin>>w>>h>>n;
        for(i=0;i<n;i++)
            scanf("%ld %ld",&c[i],&r[i]);
        r[n]=c[n]=0;
        r[n+1]=h+1;
        c[n+1]=w+1;
        sort(r,r+n+2);
        sort(c,c+n+2);
        wm=hm=0;
        for(i=1;i<n+2;i++)
        {
            wm=max(wm,c[i]-c[i-1]-1);
            hm=max(hm,r[i]-r[i-1]-1);
        }
        cout<<hm*wm<<endl;
    }
    return 0;
}
 