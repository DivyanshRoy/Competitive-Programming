// Problem Link: https://codeforces.com/contest/902/problem/B

#include<bits/stdc++.h>
using namespace std;
#define MAX 10005
  
vector<long long int> child[MAX];
long long int color[MAX],ans=0;
  
void dfs(long long int cur,long long int curcolor)
{
	if(color[cur]!=curcolor)
		ans++;
	
	for(long int i=0;i<child[cur].size();i++)
	{
		dfs(child[cur][i],color[cur]);
	}
}
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,i,p,c;
	
	cin>>n;
	
	for(i=2;i<=n;i++)
	{
		cin>>p;
		child[p].push_back(i);
	}
	
	for(i=1;i<=n;i++)
		cin>>color[i];
		
	dfs(1,0);
	cout<<ans;
	return 0;
}   