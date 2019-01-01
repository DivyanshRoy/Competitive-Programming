// Problem Link: https://www.codechef.com/APRIL17/problems/DISHLIFE

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t,n,k,i,j,p,cnt,v,no;
    bool b[100005],is;
    cin>>t;
    while(t--)
    {
        cin>>n>>k;
        for(i=0;i<=k;i++)
            b[i]=0;
        cnt=no=0;
        for(i=1;i<=n;i++)
        {
            is=1;
            scanf("%ld",&p);
            for(j=0;j<p;j++)
            {
                scanf("%ld",&v);
                if(!b[v])
                {
                    b[v]=1;
                    is=0;
                    cnt++;
                }
            }
            if(is)
                no++;
        }
        if(cnt<k)
            cout<<"sad\n";
        else if(no>0)
            cout<<"some\n";
        else
            cout<<"all\n";
    }
    return 0;
}
