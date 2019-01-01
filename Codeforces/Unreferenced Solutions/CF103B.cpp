#include<bits/stdc++.h>
using namespace std;

long int root[101],len[101];

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

int main()
{
    long int cnt=0,n,m,i,u,v;
    cin>>n>>m;
    for(i=1;i<=n;i++)
    {
        root[i]=i;
        len[i]=1;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%ld %ld",&u,&v);
        uni(u,v);
    }
    for(i=1;i<=n;i++)
    {
        if(root[i]==i)
        {
            if(len[i]>3)
                cnt++;
        }
    }
    if(cnt>2)
    {
        cout<<"FHTAGN!";
    }
    else
        cout<<"NO";
    return 0;
}
