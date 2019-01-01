// Problem Link: https://www.codechef.com/JUNE17/problems/PRMQ

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define INF 1000000007
#define dt long int

bool is[1000005];
long int divisor[1000005];

void sieve()
{
    long int mx=1000005,i,j;
    for(i=0;i<mx;i++)
        is[i]=1,divisor[i]=i;
    for(i=2;i<mx;i++)
    {
        if(!is[i])
            continue;
        for(j=i+i;j<mx;j+=i)
        {
            if(is[j])
            {
                is[j]=0;
                divisor[j]=i;
            }
        }
    }
}

struct seg
{
    dt mn,x;
    vector<dt> pf,pc,ps;
};

seg tree[4*MAXN];

dt arr[MAXN];

void build(dt s,dt e,dt i)
{
    if(s>e)
        return;
    if(s==e)
    {
        dt val=arr[s];
        while(val>1)
        {
            if(tree[i].pf.empty()||tree[i].pf.back()!=divisor[val])
            {
                tree[i].pf.push_back(divisor[val]);
                tree[i].pc.push_back(1);
            }
            else
            {
                tree[i].pc.back()++;
            }
            val/=divisor[val];
        }
        tree[i].ps.push_back(tree[i].pc[0]);
        for(dt j=1;j<tree[i].pf.size();j++)
        {
            tree[i].ps.push_back(tree[i].ps[j-1]+tree[i].pc[j]);
        }
        return;
    }
    build(s,(s+e)/2,2*i);
    build(1+(s+e)/2,e,(2*i)+1);
    vector<dt>::iterator i1=tree[2*i].pf.begin(),i2=tree[(2*i)+1].pf.begin(),ic1=tree[2*i].pc.begin(),ic2=tree[(2*i)+1].pc.begin();
    while(i1!=tree[2*i].pf.end()&&i2!=tree[(2*i)+1].pf.end())
    {
        if(*i1==*i2)
        {
            tree[i].pf.push_back(*i1);
            tree[i].pc.push_back(*ic1+*ic2);
            i1++,i2++,ic1++,ic2++;
        }
        else if(*i1<*i2)
        {
            tree[i].pf.push_back(*i1);
            tree[i].pc.push_back(*ic1);
            i1++,ic1++;
        }
        else
        {
            tree[i].pf.push_back(*i2);
            tree[i].pc.push_back(*ic2);
            i2++,ic2++;
        }
    }
    while(i1!=tree[2*i].pf.end())
    {
        tree[i].pf.push_back(*i1);
        tree[i].pc.push_back(*ic1);
        i1++,ic1++;
    }
    while(i2!=tree[(2*i)+1].pf.end())
    {
        tree[i].pf.push_back(*i2);
        tree[i].pc.push_back(*ic2);
        i2++,ic2++;
    }

    tree[i].ps.push_back(tree[i].pc[0]);
    for(dt j=1;j<tree[i].pf.size();j++)
    {
        tree[i].ps.push_back(tree[i].ps[j-1]+tree[i].pc[j]);
    }
}

dt query(dt l,dt r,dt s,dt e,dt i,dt x,dt y)
{
    if(l>r||s>e)
        return 0;
    if(l>e||r<s)
        return 0;
    if(l<=s&&e<=r)
    {
        dt ans=0;
        vector<dt>::iterator iter,itc;
        dt lo,hi,mid,a,b;
        a=distance(tree[i].pf.begin(),lower_bound(tree[i].pf.begin(),tree[i].pf.end(),x));
        b=distance(tree[i].pf.begin(),upper_bound(tree[i].pf.begin(),tree[i].pf.end(),y));
        b--;
        if(a>b)
            return 0;
        if(a==0)
            ans+=tree[i].ps[b];
        else
            ans+=(tree[i].ps[b]-tree[i].ps[a-1]);
        return ans;
    }
    dt m1=query(l,r,s,(s+e)/2,2*i,x,y);
    dt m2=query(l,r,1+(s+e)/2,e,(2*i)+1,x,y);
    return (m1+m2);
}

int main()
{
    sieve();
    dt n,q,i,l,r,x,y;
    scanf("%ld",&n);
    for(i=0;i<n;i++)
        scanf("%ld",&arr[i]);
    build(0,n-1,1);
    scanf("%ld",&q);
    while(q--)
    {
        scanf("%ld %ld %ld %ld",&l,&r,&x,&y);
        cout<<query(l-1,r-1,0,n-1,1,x,y)<<endl;
    }
    return 0;
}
