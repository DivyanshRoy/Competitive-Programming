stack<long long int> dijk_st;
long long int dist[100005];

vector< pair<long long int,long long int> > vec;

void dijkstra(long long int source)
{
	dijk_st.push(source);
	long long int cur,elem,wt;
	while(!dijk_st.empty())
	{
		cur=dijk_st.top();
		dijk_st.pop();
		vector< pair<long long int,long long int> >::iterator iter;

		for(iter=vec[cur].begin();iter!=vec[cur].end();iter++)
		{
			elem=iter->first;
			wt=iter->second;
			if( (dist[cur]+wt) < dist[elem] )
			{
				dist[elem] = dist[cur]+wt;
				dijk_st.push(elem);
			}
		}
	}
}

int main()
{
	long long int n,m,u,v,w,i,s;
	cin>>n>>m;
	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>w;
		vec[u].push_back(make_pair(v,w))
		vec[v].push_back(make_pair(u,w));

	}
	for(i=1;i<=n;i++)
		dist[i]=100000000000000000;
	cin>>s;	
	dist[s]=0;
	dijkstra(s);
}