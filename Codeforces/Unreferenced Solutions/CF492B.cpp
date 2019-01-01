#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,l,i,val;
    cin>>n>>l;
    set<long int> s;
    //s.insert(0);
    //s.insert(l);
    for(i=0;i<n;i++)
    {
        scanf("%ld",&val);
        s.insert(val);
    }
    long int mx=0;
    set<long int>::iterator iter,iter1=s.begin();
    iter1++;
    for(iter=s.begin();iter1!=s.end();iter++,iter1++)
    {
        mx=max(mx,*iter1-*iter);
    }
    iter=s.begin();
    iter1--;
    double d=(double)mx/(double)2;
    if(d<(double)*iter-(double)0)
        d=(double)*iter-(double)0;
    if(d<(double)l-(double)*iter1)
        d=(double)l-(double)*iter1;
    cout<<fixed<<setprecision(10);
    cout<<d;
    return 0;
}
