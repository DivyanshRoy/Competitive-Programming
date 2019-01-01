#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,m,i,j;
    cin>>n>>m;
    if(n>m+1||m>(2*(n+1)))
    {
        cout<<-1;
        return 0;
    }
    if(n==m+1)
    {
        cout<<0;
        for(i=0;i<m;i++)
            cout<<"10";
        return 0;
    }
    else if(n==m)
    {
        for(i=0;i<n;i++)
            cout<<"10";
    }
    else if(n==m-1)
    {
        cout<<1;
        for(i=0;i<n;i++)
        {
            cout<<"01";
        }
    }
    else
    {

        m-=2;
        n--;
        while((m-n)!=1)
        {
            cout<<"110";
            m-=2;
            if(n)
                n--;
            else
                break;
        }
        if(m==0&&n==0)
        {
            cout<<"11";
            return 0;
        }
        else{
            cout<<"110";
        }
        cout<<1;
        for(i=0;i<n;i++)
            cout<<"01";
    }
    return 0;
}
