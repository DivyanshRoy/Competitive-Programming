// Problem Link: https://www.codechef.com/JUNE17/problems/CLONEME

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define dt long long int
#define MAXN 100005

struct seg
{
    vector<dt> vec;
};

seg tree[4*MAXN];

dt arr[MAXN];

void build(dt s,dt e,dt i)
{
    if(s>e)
        return;
    if(s==e)
    {
        tree[i].vec.clear();
        tree[i].vec.push_back(arr[s+1]);
        return;
    }
    build(s,(s+e)/2,2*i);
    build(1+(s+e)/2,e,(2*i)+1);
    vector<dt>::iterator iter1,iter2;
    iter1=tree[2*i].vec.begin();
    iter2=tree[(2*i)+1].vec.begin();
    tree[i].vec.clear();
    while(iter1!=tree[2*i].vec.end()&&iter2!=tree[(2*i)+1].vec.end())
    {
        if(*iter1<*iter2)
        {
            tree[i].vec.push_back(*iter1);
            iter1++;
        }
        else
        {
            tree[i].vec.push_back(*iter2);
            iter2++;
        }
    }
    while(iter1!=tree[2*i].vec.end())
    {
        tree[i].vec.push_back(*iter1);
        iter1++;
    }
    while(iter2!=tree[(2*i)+1].vec.end())
    {
        tree[i].vec.push_back(*iter2);
        iter2++;
    }
}

bool bs(dt l,dt r,dt s,dt e,dt i,dt v)
{
    if(l>r||s>e)
        return 0;
    if(l>e||r<s)
        return 0;
    if(l<=s&&e<=r)
    {
        return binary_search(tree[i].vec.begin(),tree[i].vec.end(),v);
    }
    bool m1=bs(l,r,s,(s+e)/2,2*i,v);
    bool m2=bs(l,r,1+(s+e)/2,e,(2*i)+1,v);
    return (m1||m2);
}

dt num(dt l,dt r,dt s,dt e,dt i,dt a,dt b)
{
    if(l>r||s>e)
        return 0;
    if(l>e||r<s)
        return 0;
    if(l<=s&&e<=r)
    {
        return distance(tree[i].vec.begin(),lower_bound(tree[i].vec.begin(),tree[i].vec.end(),b))-distance(tree[i].vec.begin(),upper_bound(tree[i].vec.begin(),tree[i].vec.end(),a));
    }
    dt m1=num(l,r,s,(s+e)/2,2*i,a,b);
    dt m2=num(l,r,1+(s+e)/2,e,(2*i)+1,a,b);
    return (m1+m2);
}

long long int modInverse(long long int a,long long int m)
{
    if(m==0)
        return 1;
    long long int p=modInverse(a,m/2)%mod;
    p=(p*p)%mod;
    return (m%2==0)?p:(a*p)%mod;
}

int main()
{
    long long int n,i,ans=1,power[100005],pre[100005],prem[100005],mul,q,t,a,b,c,d,lo,hi,mid,tmp;
    map<long long int,long long int> sp;
    mul=100003;
    power[0]=1;
    for(i=1;i<=mul;i++)
    {
        ans=(ans*mul)%mod;
        power[i]=ans;
        sp[ans]=i;
    }
    pre[0]=0;
    prem[0]=1;
    cin>>t;
    while(t--)
    {
        scanf("%lld %lld",&n,&q);
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            pre[i]=(pre[i-1]+power[arr[i]])%mod;
            prem[i]=(prem[i-1]*power[arr[i]])%mod;
        }
        build(0,n-1,1);
        while(q--)
        {
            scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
            if((pre[b]-pre[a-1]+mod)%mod==(pre[d]-pre[c-1]+mod)%mod)
            {
                cout<<"YES\n";
            }
            else
            {
                long long int s,v,d1,d2,i1,i2;
                s=((pre[b]-pre[a-1]+mod)%mod-(pre[d]-pre[c-1]+mod)%mod+mod)%mod;
                v=((prem[b]*modInverse(prem[a-1],mod-2))%mod*modInverse((prem[d]*modInverse(prem[c-1],mod-2))%mod,mod-2))%mod;
                d2=(s*modInverse(v-1,mod-2))%mod;
                d1=(s+d2)%mod;
                if(sp.find(d1)==sp.end()||sp.find(d2)==sp.end())
                {
                    cout<<"NO\n";
                }
                else
                {
                    i1=sp[d1];
                    i2=sp[d2];
                    if(bs(a-1,b-1,0,n-1,1,i1)&&bs(c-1,d-1,0,n-1,1,i2))
                    {
                        if(num(a-1,b-1,0,n-1,1,min(i1,i2),max(i1,i2))>0||num(c-1,d-1,0,n-1,1,min(i1,i2),max(i1,i2))>0)
                        {
                            cout<<"NO\n";
                        }
                        else
                        {
                            cout<<"YES\n";
                        }
                    }
                    else
                    {
                        cout<<"NO\n";
                    }
                }
            }
        }
    }
    return 0;
}
