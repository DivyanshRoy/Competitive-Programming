#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int T,a,b,c,d,e,f;
    cin>>T;
    while(T--)
    {
        scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
        if(d<a)
        {
            cout<<0<<endl;
            continue;
        }
        if(d<b)
        {
            f=(c-a)*(d-c+1);
            f+=((d-c)*(d-c+1))/2;
            cout<<f<<endl;
            continue;
        }
        if(a>c)
        {
            cout<<((d-a)*(d-a+1))/2<<endl;
            continue;
        }
        f=(b-a+1)*(d-c+1);
        if(b>=c)
        {
            e=b-c;
            f-=((e+1)*(e+2))/2;
        }
        cout<<f<<endl;
    }
    return 0;
}
