#include<bits/stdc++.h>
using namespace std;

map<int, vector<int> > mx,my;
int len[101],root[101];

int froot(int a)
{
    while(a!=root[a])
        a=root[a];
    return a;
}

void uni(int a,int b)
{
    int ra,rb;
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
    int n,i,x[101],y[101];
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x[i]>>y[i];
        mx[x[i]].push_back(i);
        my[y[i]].push_back(i);
        len[i]=1;
        root[i]=i;
    }
    vector<int>::iterator iter;
    for(i=1;i<=n;i++)
    {
        for(iter=mx[x[i]].begin();iter!=mx[x[i]].end();iter++)
            uni(i,*iter);
        for(iter=my[y[i]].begin();iter!=my[y[i]].end();iter++)
            uni(i,*iter);
    }
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        if(root[i]==i)
            cnt++;
    }
    cout<<cnt-1;
    return 0;
}
