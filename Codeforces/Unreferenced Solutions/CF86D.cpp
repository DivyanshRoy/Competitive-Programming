#include<bits/stdc++.h>
using namespace std;

map<long int,long int> value;
map< pair<long int,long int> , set<long int> > elem;
map< pair<long int,long int> , map<long int,long int> > freq;
map< pair<long int,long int> , long long int> total;

void dp(long int l,long int r,long int a,long int b,long int n,set<long int> s)
{
    if(l>r)
        return;
    set<long int>::iterator iter;
    long long int sum=0,e;
    for(iter=elem[make_pair(1,n)].begin();iter!=elem[make_pair(1,n)].end();iter++)
    {
        if(freq[make_pair(a,b)][*iter]>0)
        {
            //elem[make_pair(l,r)].insert(*iter);
            freq[make_pair(l,r)][*iter]=freq[make_pair(a,b)][*iter];
            e=freq[make_pair(1,n)][*iter]-freq[make_pair(a,b)][*iter];
            sum+=((e*e)*(*iter));
        }
    }
    for(iter=s.begin();iter!=s.end();iter++)
    {
        sum-=(((2*(e-1))+1)*(*iter));
        freq[make_pair(l,r)][*iter]++;
    }
    if(l==a)
    {
        e=freq[make_pair(1,n)][value[b]]-freq[make_pair(a,b)][value[b]];
        if(e==1)
        {
            s.insert(b);
            //elem[make_pair(l,r)].erase(*iter);
        }
        if(e>0)
        {
            sum-=(((2*(e-1))+1)*(value[b]));
            freq[make_pair(l,r)][value[b]]++;
        }
    }
    else
    {
        e=freq[make_pair(1,n)][value[a]]-freq[make_pair(a,b)][value[a]];
        if(e==1)
        {
            s.insert(a);
            //elem[make_pair(l,r)].erase(value[a]);
        }
        if(e>0)
        {
            sum-=(((2*(e-1))+1)*(value[a]));
            freq[make_pair(l,r)][value[a]]++;
        }
    }
    total[make_pair(l,r)]=sum;
    dp(l+1,r,l,r,n,s);
    dp(l,r-1,l,r,n,s);
}

void calc(long int n)
{
    long long int i,sum=0,e,v;
    set<long int> s;
    for(i=1;i<=n;i++)
    {
        v=value[i];
        elem[make_pair(1,n)].insert(v);
        e=freq[make_pair(1,n)][value[i]];
        sum+=(((2*e)+1)*v);
        freq[make_pair(1,n)][value[i]]=e+1;
    }
    total[make_pair(1,n)]=sum;
    dp(1,n-1,1,n,n,s);
    dp(2,n,1,n,n,s);
}

int main()
{
    long long int n,t,i,val,a,b;
    cin>>n>>t;
    for(i=1;i<=n;i++)
    {
        scanf("%lld",&val);
        value[i]=val;
    }
    calc(n);
    while(t--)
    {
        scanf("%lld %lld",&a,&b);
        cout<<total[make_pair(a,b)]<<endl;
    }
    return 0;
}
