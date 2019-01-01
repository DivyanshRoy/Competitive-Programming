#include<bits/stdc++.h>
using namespace std;

vector< vector< pair< int , long int > > > elem;
long int k;
vector<bool> vis;
vector< vector<long int> > vecto;

pair <int,long int> p;
pair<long int, vector<long int> > pt;

vector< vector< pair<long int, vector<long int> > > > dp;

long int team;

void DFS(int n,int pos,vector<long int> vec,vector<bool> vi,long int ti)
{
    if(dp[pos].empty()!=1)
        return;
    if(pos==1)
    {
        vec.push_back(pos);
        //if(ti<=k)
        vecto.push_back(vec);
        vector<long int> temp;
                temp.push_back(pos);
        dp[pos].push_back(make_pair(pt.first+ti,temp));
        return;
    }
    if(vi[pos])
        return;
    vec.push_back(pos);
    vi[pos]=1;
    vector< pair< int , long int > >::iterator iter;
    for(iter=elem[pos].begin();iter!=elem[pos].end();iter++)
    {
        p=*iter;
        if(pos==n)
            team=0;
        team+=p.second;
        DFS(n,p.first,vec,vi,ti+p.second);
        vector< pair< long int,vector<long int> > >::iterator it;
        for(it=dp[iter->first].begin();it!=dp[iter->first].end();it++)
        {
            pt=*it;
            vector<long int>::iterator ite;
            vector<long int> temp;
            temp.push_back(pos);
            for(ite=(pt.second).begin();ite!=(pt.second).end();ite++)
            {
                temp.push_back(*ite);
            }
            dp[pos].push_back(make_pair(team-ti,temp));
        }
    }
}

int main()
{
    int j,n,m,i,a,b;
    long int t;
    cin>>n>>m>>k;
    elem.resize(n+2);
    dp.resize(n+2);
    for(i=0;i<m;i++)
    {
        scanf("%d %d %ld",&a,&b,&t);
        elem[b].push_back((make_pair(a,t)));
    }
    vector<long int> vec;
    vis.resize(n+1);
    for(i=0;i<n+1;i++)
        vis[i]=0;
    DFS(n,n,vec,vis,0);
    long int mx=0,pos=-1;
    for(i=0;i<dp[n].size();i++)
    {
        if(dp[n][i].second.size()>mx&&dp[n][i].first<=k)
        {
            mx=dp[n][i].second.size();
            pos=i;
        }
    }
    cout<<mx<<endl;
    for(i=mx-1;i>=0;i--)
        cout<<dp[n][pos].second[i]<<" ";
    return 0;
}
