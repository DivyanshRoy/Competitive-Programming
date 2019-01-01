#include<bits/stdc++.h>
using namespace std;

int main()
{
    int m,s,i,tmp;
    cin>>m>>s;
    if(s>(9*m))
    {
        cout<<"-1 -1";
        return 0;
    }
    tmp=s;
    for(i=1;i<=m;i++)
    {
        if(tmp-1<=9*(m-i)&&tmp>0)
        {
            cout<<1;
            tmp-=1;
        }
        else
        {
            cout<<tmp-9*(m-i);
            tmp=9*(m-i);
        }
    }
    cout<<" ";
    tmp=s;
    for(i=1;i<=m;i++)
    {
        if(tmp-9>=m-i)
        {
            cout<<9;
            tmp-=9;
        }
        else
        {
            cout<<tmp-(m-i);
            tmp=m-i;
        }
    }
    return 0;
}
