// Problem Link: https://www.spoj.com/problems/PIR/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t;
    long double u,v,w,U,V,W,u1,v1,w1,ans;
    cin>>t;
    cout<<fixed<<setprecision(4);
    while(t--)
    {
        cin>>u>>v>>w>>W>>V>>U;
        u1=v*v;
        u1+=w*w;
        u1-=U*U;
 
        v1=w*w;
        v1+=u*u;
        v1-=V*V;
 
        w1=u*u;
        w1+=v*v;
        w1-=W*W;
        ans=4*u*u*v*v*w*w;
        ans-=(u*u*u1*u1);
        ans-=(v*v*v1*v1);
        ans-=(w*w*w1*w1);
        ans+=u1*v1*w1;
        ans=sqrt(ans);
        ans/=12;
        ans=(round(ans*10000));
        ans/=10000;
 
        cout<<ans<<endl;
    }
    return 0;
}