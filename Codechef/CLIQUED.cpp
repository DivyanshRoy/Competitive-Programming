// Problem Link: https://www.codechef.com/APRIL17/problems/CLIQUED

#include<bits/stdc++.h>
using namespace std;
#define mp(a,b) make_pair(a,b)

long long int k,s,x,ans[100005],n;
bool b[100005];
unordered_map< long long int, vector< pair<long long int,long long int> > > ma;
set< pair<long long int,long long int> > se;

void bfs()
{
    queue< pair<long long int,long long int> > q;
    q.push(mp(s,0));
    se.erase(mp((long long int)1000000000000000009,s));
    b[s]=1;
    ans[s]=0;
    pair<long long int,long long int> p;
    long long int cur,pre,val,i,pv;
    vector< pair<long long int,long long int> >::iterator iter;
    set< pair<long long int,long long int> >::reverse_iterator siter;
    while(!q.empty())
    {
        p=q.front();
        q.pop();
        cur=p.first;
        b[cur]=0;
        pre=p.second;
        for(iter=ma[cur].begin();iter!=ma[cur].end();iter++)
        {
            val=ans[cur]+iter->second;
            pv=ans[iter->first];
            if(val<ans[iter->first])
            {
                ans[iter->first]=val;
                if(!b[iter->first])
                {
                    q.push(mp(iter->first,cur));
                    b[iter->first]=1;
                }
                if(iter->first<=k)
                {
                    if(val>x)
                        se.insert(mp(val,iter->first));
                    se.erase(mp(pv,iter->first));
                }
            }
        }
        if(cur<=k)
        {
            val=ans[cur]+x;
            for(siter=se.rbegin();siter!=se.rend();)
            {
                if(siter->first<=val)
                    break;
                if(val>x)
                    se.insert(mp(val,siter->second));
                if(val<ans[siter->second])
                {
                    ans[siter->second]=val;
                    if(!b[siter->second])
                    {
                        q.push(mp(siter->second,cur));
                        b[siter->second]=1;
                    }
                }
                se.erase(mp(siter->first,siter->second));
            }
        }
        /*
        if(cur<=k)
        {
            val=ans[cur]+x;
            for(i=1;i<=k;i++)
            {
                if(val<ans[i])
                {
                    ans[i]=val;
                    if(!b[i])
                    {
                        q.push(mp(i,cur));
                        b[i]=1;
                    }
                }
            }
        }
        */
    }
}

int main()
{
    long long int t,m,a,ba,c,i;
    cin>>t;
    while(t--)
    {
        ma.clear();
        se.clear();
        cin>>n>>k>>x>>m>>s;
        for(i=1;i<=n;i++)
        {
            b[i]=0;
            ans[i]=(long long int)1000000000000000009;
        }
        for(i=1;i<=k;i++)
        {
            se.insert(mp((long long int)1000000000000000009,i));
        }
        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld %lld",&a,&ba,&c);
            ma[a].push_back(mp(ba,c));
            ma[ba].push_back(mp(a,c));
        }
        bfs();
        for(i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
