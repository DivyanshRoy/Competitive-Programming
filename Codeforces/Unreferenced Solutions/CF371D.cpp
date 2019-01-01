#include<bits/stdc++.h>
using namespace std;

long int n,root[200001],len[200001],arr[200001],fil[200001];

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
    root[rb]=root[ra];
    len[ra]+=len[rb];
}

void pour(long int p,long int q)
{
    p=froot(p);
    while(q>=0&&p<=n)
    {
    	if(p==0)
    	return;
        if(q<=(arr[p]-fil[p]))
        {
            fil[p]+=q;
            q=0;
        }
        else
        {
            q-=arr[p]-fil[p];
            fil[p]=arr[p];
            uni(p+1,p);
            p++;
            if(p>n)
            	return;
            p=froot(p);
        }
    }
}

int main()
{
    long int m,i,a,b,c;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&arr[i]);
        fil[i]=0;
        root[i]=i;
        len[i]=1;
    }
    cin>>m;
    for(i=1;i<=m;i++)
    {
        cin>>a;
        if(a==1)
        {
            cin>>b>>c;
            pour(b,c);
        }
        else
        {
            cin>>b;
            cout<<fil[b]<<endl;
        }
    }
    return 0;
}
