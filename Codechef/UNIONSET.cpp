// Problem Link: https://www.codechef.com/JUNE17/problems/UNIONSET

#include<bits/stdc++.h>
using namespace std;

int main()
{
    bool b[2501][2501];
    long int i,j,t,n,k,no,v,ans,l;
    cin>>t;
    while(t--)
    {
        for(i=0;i<2501;i++)
        {
            for(j=0;j<2501;j++)
                b[i][j]=0;
        }
        scanf("%ld %ld",&n,&k);
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&no);
            for(j=1;j<=no;j++)
            {
                scanf("%ld",&v);
                b[i][v]=1;
            }
        }
        ans=0;
        for(i=1;i<=n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                for(l=1;l<=k;l++)
                {
                    if(b[i][l]==0&&b[j][l]==0)
                        break;
                }
                if(l==k+1)
                    ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
