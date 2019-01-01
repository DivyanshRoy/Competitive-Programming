#include<bits/stdc++.h>
using namespace std;


int main()
{
    long int n,i,diff=0,ch=0,add=0;
    cin>>n;
    int c[200000],d[200000];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&c[i],&d[i]);
    }
    bool pos,pos1=0,fou=0;
    if(c[0]<0)
        pos=0;
    else
    {
        pos=1;
        pos1=1;
    }

    diff+=c[0];
    if(c[0])
        add+=c[0];
    long int cr,ub=100000,lb=0;
    bool a1,a2;
    a1=a2=1;
    if(d[0]==1)
    {
        a2=0;
        lb=1900;

    }
    else
    {
        a1=0;
        ub=1899;

    }
    long int tmp;
    for(i=1;i<n;i++)
    {
        if(c[i])
            add+=c[i];
        if(d[i]==1)
            a2=0;
        else
            a1=0;
        if(c[i-1]==0&&d[i-1]!=d[i])
        {
            cout<<"Impossible";
            return 0;
        }
        if(pos==0&&d[i-1]==2&&d[i]==1)
        {
            cout<<"Impossible";
            return 0;
        }
        if(pos==1&&d[i-1]==1&&d[i]==2)
        {
            cout<<"Impossible";
            return 0;
        }
        if(d[i]==2)
        {
            tmp=1900-diff-1;
            ub=min(ub,tmp);
        }
        else
        {
            tmp=1900-diff;
            lb=max(lb,tmp);
        }
        diff+=c[i];
        if(c[i]>0)
        {
            pos1=1;
            pos=1;
        }
        else
            pos=0;
    }
    cr=ub+diff;
    if(a1)
      cout<<"Infinity";
    else if(a2&&diff>0)
    {
        cout<<1899+c[n-1];
    }
    else if(a2&&diff==0)
    {
        cout<<1899-add;
    }
    else
        cout<<cr;
	return 0;
}
