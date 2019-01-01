// Problem Link: https://codeforces.com/contest/369/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

vector< vector< pair<long long int,long long int> > > vec;
long long int below[MAX];
vector<long long int> ans;

void dfs1(long long int cur,long long int pre)
{
	below[cur]=0;
	
	vector< pair<long long int,long long int> >::iterator iter;
	
	for(iter=vec[cur].begin();iter!=vec[cur].end();iter++)
	{
		if(iter->first==pre)
			continue;
			
		if(iter->second==2)
			below[cur]++;
		dfs1(iter->first,cur);
		below[cur]+=below[iter->first];
	}
}

long long int bad=0;

void dfs2(long long int cur,long long int pre)
{
	vector< pair<long long int,long long int> >::iterator iter;
	
	if(bad>0&&below[cur]==0)
	{
		ans.push_back(cur);
		return;
	}
	
	for(iter=vec[cur].begin();iter!=vec[cur].end();iter++)
	{
		if(iter->first==pre)
			continue;
			
		if(iter->second==2)
			bad++;
		else
		{
			if(below[iter->first]==0)
				continue;
		}
		dfs2(iter->first,cur);
		
		if(iter->second==2)
			bad--;
		
	}
}

int main()
{

	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,i,u,v,d;	
	vector< pair<long long int,long long int> > emptyvec;
	
	cin>>n;
	for(i=0;i<=n;i++)
		vec.push_back(emptyvec);
		
	for(i=1;i<n;i++)
	{
		cin>>u>>v>>d;
		vec[u].push_back({v,d});
		vec[v].push_back({u,d});
	}
	
	dfs1(1,0);
	dfs2(1,0);
	
	cout<<ans.size()<<endl;
	for(i=0;i<ans.size();i++)
		cout<<ans[i]<<" ";
	return 0;
}