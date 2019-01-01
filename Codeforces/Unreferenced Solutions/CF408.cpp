#include<bits/stdc++.h>
using namespace std;


int main()
{
    long int mx=-1000000009,ans=-1000000009,tmp,n,i,arr[300005],u,v,node[300005]={-1000000009},c[300005]={0};
    unordered_map<long int,vector<long int> > ma;
    cin>>n;

    for(i=1;i<=n;i++)
    {
        scanf("%ld",&arr[i]);
        mx=max(arr[i],mx);
    }
    set<long int> se;
    ans=mx;
    for(i=1;i<=n;i++)
    {
        if(arr[i]==mx)
            se.insert(i);
    }
    for(i=1;i<n;i++)
    {
        scanf("%ld %ld",&u,&v);
        if(arr[u]==mx&&arr[v]==mx)
        {
            ans=max(ans,mx+1);
        }
        if(arr[u]==mx)
        {ans=max(ans,mx+1);
        }
        if(arr[v]==mx)
        {
            if(node[u]==mx)
            {
                ans=max(ans,mx+1);
            }
        }
        if(node[u]==arr[v])
        {
        	c[u]++;
        }
        else if(arr[v]>node[u])
        {
        	node[u]=arr[v];
        	c[u]=1;
        }

        if(node[v]==arr[u])
        {
        	c[v]++;
        }
        else if(arr[u]>node[v])
        {
        	node[v]=arr[u];
        	c[v]=1;
        }
        ma[u].push_back(v);
        ma[v].push_back(u);
    }
    set<long int>::iterator iter;
    vector<long int>::iterator viter;
    long int cnt=0;
    for(iter=se.begin();iter!=se.end();iter++)
    {
        cnt=0;
        for(viter=ma[*iter].begin();viter!=ma[*iter].end();viter++)
        {
            if(node[*viter]==mx&&c[*viter]>1)
                cnt++;
        }
        if(cnt>1)
        {
            ans=max(ans,mx+cnt*(cnt-1));
            break;
        }
    }
    cout<<ans;
    return 0;
}
