// Problem Link: https://www.codechef.com/problems/ENTRY

#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define INF 1000000007
#define dt long int

struct seg
{
    dt dig[10];
    dt sum,x;
};

seg tree[4*MAXN];

dt arr[MAXN];

void build(dt s,dt e,dt i)
{
    if(s>e)
        return;
    for(dt j=0;j<10;j++)
        tree[i].dig[j]=0;
    tree[i].dig[0]=(e-s+1);
    if(s==e)
    {
        tree[i].sum=0;
        tree[i].x=0;
        return;
    }
    build(s,(s+e)/2,2*i);
    build(1+(s+e)/2,e,(2*i)+1);
    tree[i].sum=(tree[2*i].sum+tree[(2*i)+1].sum);
    tree[i].x=0;
}

void update(dt l,dt r,dt s,dt e,dt v,dt i)
{
    if(l>r||s>e)
        return;
    if(tree[i].x!=0)
    {
        dt tmp[10];
        for(dt j=0;j<10;j++)
        {
            tmp[(j+tree[i].x)%10]=tree[i].dig[j];
        }
        for(dt j=0;j<10;j++)
            tree[i].dig[j]=tmp[j];
        tree[i].sum=0;
        for(dt j=0;j<10;j++)
            tree[i].sum+=(j*tmp[j]);
        if(s!=e)
        {
            tree[2*i].x+=tree[i].x;
            tree[(2*i)+1].x+=tree[i].x;
        }
        tree[i].x=0;
    }
    if(l>e||r<s)
        return;
    if(l<=s&&e<=r)
    {
        dt tmp[10];
        for(dt j=0;j<10;j++)
        {
            tmp[(j+v)%10]=tree[i].dig[j];
        }
        for(dt j=0;j<10;j++)
            tree[i].dig[j]=tmp[j];
        tree[i].sum=0;
        for(dt j=0;j<10;j++)
            tree[i].sum+=(j*tmp[j]);
        if(s!=e)
        {
            tree[2*i].x+=v;
            tree[(2*i)+1].x+=v;
        }
        return;
    }
    if(s==e)
        return;
    update(l,r,s,(s+e)/2,v,2*i);
    update(l,r,1+(s+e)/2,e,v,(2*i)+1);
    for(dt j=0;j<10;j++)
        tree[i].dig[j]=tree[2*i].dig[j]+tree[(2*i)+1].dig[j];
    tree[i].sum=0;
    for(dt j=0;j<10;j++)
        tree[i].sum+=(j*tree[i].dig[j]);
}

dt query(dt l,dt r,dt s,dt e,dt i)
{
    if(l>r||s>e)
        return 0;
    if(tree[i].x!=0)
    {
        dt tmp[10];
        for(dt j=0;j<10;j++)
        {
            tmp[(j+tree[i].x)%10]=tree[i].dig[j];
        }
        for(dt j=0;j<10;j++)
            tree[i].dig[j]=tmp[j];
        tree[i].sum=0;
        for(dt j=0;j<10;j++)
            tree[i].sum+=(j*tmp[j]);
        if(s!=e)
        {
            tree[2*i].x+=tree[i].x;
            tree[(2*i)+1].x+=tree[i].x;
        }
        tree[i].x=0;
    }
    if(l>e||r<s)
        return 0;
    if(l<=s&&e<=r)
        return tree[i].sum;
    dt m1=query(l,r,s,(s+e)/2,2*i);
    dt m2=query(l,r,1+(s+e)/2,e,(2*i)+1);
    return (m1+m2);
}

int main()
{
    dt n,q,i,a,b,c;
    cin>>n>>q;
    build(0,n-1,1);
    while(q--)
    {
        scanf("%ld %ld %ld",&a,&b,&c);
        if(a==1)
        {
            update(b-1,c-1,0,n-1,1,1);
        }
        else
        {
            cout<<query(b-1,c-1,0,n-1,1)<<endl;
        }
    }
    return 0;
}
