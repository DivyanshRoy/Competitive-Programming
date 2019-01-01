// Problem Link: https://www.codechef.com/AUG17/problems/GCAC

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t,n,m,mnsal[1005],osal[1005],mjo[1005],cjo[1005],j,i,b;
    long long int sum=0,cnt=0,un=0;
    char qual[1005][1005];
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(i=1;i<=n;i++)
            cin>>mnsal[i];
        for(i=1;i<=m;i++)
        {
            cjo[i]=0;
            cin>>osal[i]>>mjo[i];
        }
        for(i=1;i<=n;i++)
        {
            cin>>qual[i];
        }
        sum=cnt=un=0;
        long long int mx,ind;
        for(i=1;i<=n;i++)
        {
            mx=-1;
            ind=-1;
            for(j=1;j<=m;j++)
            {
                if(qual[i][j-1]=='0')
                    continue;
                if(cjo[j]>=mjo[j])
                    continue;
                if(osal[j]<mnsal[i])
                    continue;
                if(osal[j]>mx)
                {
                    mx=osal[j];
                    ind=j;
                }
            }
            if(mx==-1)
            {
                
            }
            else
            {
                cnt++;
                sum+=osal[ind];
                cjo[ind]++;
            }
        }
        for(i=1;i<=m;i++)
        {
            if(cjo[i]==0)
                un++;
        }
        cout<<cnt<<" "<<sum<<" "<<un<<endl;
    }
    return 0;
}
