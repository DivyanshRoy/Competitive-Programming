#include<bits/stdc++.h>
using namespace std;

long int root[100001],len[100001];

long int froot(long int a)
{
    while(a!=root[a])
        a=root[a];
    return a;
}

void uni(long int a,long int b)
{
    long int ra,rb;
    ra=froot(a);
    rb=froot(b);
    if(ra==rb)
        return;
    if(len[ra]>len[rb])
    {
        root[rb]=root[ra];
        len[ra]+=len[rb];
    }
    else
    {
        root[ra]=root[rb];
        len[rb]+=len[ra];
    }
}

long int c[100001];
map<long int, vector<long int> > vec;

int main()
{
    long int n,i,u,v;
    cin>>n;
    for(i=1;i<n;i++)
    {
        scanf("%ld %ld",&u,&v);
        vec[u].push_back(v);
        vec[v].push_back(u);
        root[i]=i;
        len[i]=1;
    }
    root[n]=n;
    len[n]=1;
    vector<long int>::iterator iter;
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&c[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(iter=vec[i].begin();iter!=vec[i].end();iter++)
        {
            if(c[i]==c[*iter])
                uni(i,*iter);
        }
    }
    long int cnt=0,tmp;
    for(i=1;i<=n;i++)
    {
        if(root[i]==i)
            cnt++;
    }
    for(i=1;i<=n;i++)
    {
        tmp=0;
        for(iter=vec[i].begin();iter!=vec[i].end();iter++)
        {
            if(c[i]!=c[*iter])
                tmp++;
        }
        if(cnt-1==tmp)
        {
            cout<<"YES\n"<<i;
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
