#include<bits/stdc++.h>
using namespace std;
#define MAXN 100005
#define INF 1000000007
#define dt long long int

struct seg
{
    dt mn,x;
};

seg tree[4*MAXN];

dt arr[MAXN];

void build(dt s,dt e,dt i)
{
    if(s>e)
        return;
    if(s==e)
    {
        tree[i].mn=arr[s];
        tree[i].x=0;
        return;
    }
    build(s,(s+e)/2,2*i);
    build(1+(s+e)/2,e,(2*i)+1);
    tree[i].mn=min(tree[2*i].mn,tree[(2*i)+1].mn);
    tree[i].x=0;
}

void update(dt l,dt r,dt s,dt e,dt v,dt i)
{
    if(l>r||s>e)
        return;
    if(tree[i].x!=0)
    {
        tree[i].mn+=tree[i].x;
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
        tree[i].mn+=v;
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
    tree[i].mn=min(tree[2*i].mn,tree[(2*i)+1].mn);
}

dt query(dt l,dt r,dt s,dt e,dt i)
{
    if(l>r||s>e)
        return INF;
    if(tree[i].x!=0)
    {
        tree[i].mn+=tree[i].x;
        if(s!=e)
        {
            tree[2*i].x+=tree[i].x;
            tree[(2*i)+1].x+=tree[i].x;
        }
        tree[i].x=0;
    }
    if(l>e||r<s)
        return INF;
    if(l<=s&&e<=r)
        return tree[i].mn;
    dt m1=query(l,r,s,(s+e)/2,2*i);
    dt m2=query(l,r,1+(s+e)/2,e,(2*i)+1);
    return min(m1,m2);
}

int main()
{

    return 0;
}
