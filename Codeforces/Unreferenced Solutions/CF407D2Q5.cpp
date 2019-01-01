#include<bits/stdc++.h>
using namespace std;

vector<long int> vec;

long int bfs()
{
    queue<long int> q;
    q.push(0);
    long int cur,val,len[2005];
    bool vis[2005];
    len[1000]=0;
    vis[1000]=1;
    vector<long int>::iterator iter;
    while(!q.empty())
    {
        cur=q.front();
        q.pop();
        for(iter=vec.begin();iter!=vec.end();iter++)
        {
            val=cur+*iter;
            if(val>1000||val<-1000)
                continue;
            else if(val==0)
                return len[cur+1000]+1;
            else if(!vis[val+1000])
            {
                vis[val+1000]=1;
                len[val+1000]=len[cur+1000]+1;
                q.push(val);
            }
        }
    }
    return -1;
}

int main()
{
    long int n,k,i,v;
    bool is[1005]={0};
    cin>>n>>k;
    for(i=0;i<k;i++)
    {
        scanf("%ld",&v);
        is[v]=1;
    }
    for(i=0;i<=1000;i++)
    {
        if(is[i])
            vec.push_back(i-n);
    }
    cout<<bfs();
    return 0;
}
