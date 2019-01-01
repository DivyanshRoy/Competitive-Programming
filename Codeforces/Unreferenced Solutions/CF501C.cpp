#include<bits/stdc++.h>
using namespace std;

int main()
{
    unsigned int n,i,d,s;
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    bool vis[n]={0};
    queue<unsigned int> q;
    map<unsigned int, pair<unsigned int,unsigned int> > ma;  //i then d then s
    for(i=0;i<n;i++)
    {
        cin>>d>>s;
        if(d==1)
        {
            q.push(i);
        }
        ma[i]=make_pair(d,s);
    }
    vector< pair<unsigned int,unsigned int> > vec;
    unsigned int un,de;
    while(!q.empty())
    {
        if(ma[q.front()].first==0)
        {
            q.pop();
            continue;
        }
        if(ma[q.front()].first!=1)
        {
            q.push(q.front());
            q.pop();
            continue;
        }
        if(vis[q.front()])
        {
            q.pop();
            continue;
        }
        vis[q.front()]=1;
        if(!ma[q.front()].first)
        {
            q.pop();
            continue;
        }
        un=ma[q.front()].second;
        de=ma[q.front()].first;
        vec.push_back(make_pair(q.front(),un));
        ma[un].second^=q.front();
        ma[un].first--;
        ma[q.front()].first--;
        if(!vis[un])
        {
            q.push(un);
        }
        q.pop();
    }
    cout<<vec.size()<<endl;
    vector< pair<unsigned int,unsigned int> >::iterator iter;
    for(iter=vec.begin();iter!=vec.end();iter++)
    {
        cout<<iter->first<<" "<<iter->second<<endl;
    }
    return 0;
}
