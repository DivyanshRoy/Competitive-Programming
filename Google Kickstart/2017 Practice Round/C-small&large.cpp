#include<bits/stdc++.h>
using namespace std;

int main()
{
    freopen("C-large.in","r",stdin);
    freopen("outputC.out","w",stdout);
    long long int t,i,l,r,n,m;
    cin>>t;
    for(i=1;i<=t;i++)
    {
        cin>>l>>r;
        n=min(l,r);
        m=(n*(n+1))/2;
        cout<<"Case #"<<i<<": "<<m<<endl;
    }
    return 0;
}
