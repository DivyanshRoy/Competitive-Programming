// Problem Link: https://www.spoj.com/problems/TRIGALGE/

#include<bits/stdc++.h>
using namespace std;
 
long double a,b,c;
 
void calc()
{
    long double lo,hi,mid,val,df,ds;
    lo=0;
    hi=(long double)100000;
    mid=(lo+hi)/2;
    val=(a*mid)+(b*sin(mid));
    ds=df=val-c;
    if(df<0)
        df*=(long double)-1;
    while(df>(long double)0.000001)
    {
        if(ds>0)
            hi=mid;
        else
            lo=mid;
        mid=(lo+hi)/2;
        val=(a*mid)+(b*sin(mid));
        ds=df=val-c;
        if(df<0)
            df*=(long double)-1;
    }
    printf("%Lf\n",mid);
}
 
int main()
{
    long long int t;
    scanf("%lld",&t);
    while(t--)
    {
        //scanf("%Lf %Lf %Lf",&a,&b,&c);
        cin>>a>>b>>c;
        calc();
    }
    return 0;
}