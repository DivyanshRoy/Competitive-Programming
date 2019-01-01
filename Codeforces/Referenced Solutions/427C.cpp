// Problem Link: https://codeforces.com/contest/427/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
#define mod 1000000007
long long int arr[MAX],sum=0,pro=1;


#define NIL -1

class Graph
{
	long long int V;
	vector<long long int> *adj; 

	void SCCUtil(long long int u, long long int disc[], long long int low[],stack<long long int> *st, bool stackMember[]);
	
	public:
	
	Graph(long long int V);
	void addEdge(long long int v, long long int w); 
	void SCC(); 
};

Graph::Graph(long long int V)
{
	this->V = V;
	adj = new vector<long long int>[V];
}

void Graph::addEdge(long long int v, long long int w)
{
	adj[v].push_back(w);
}

void Graph::SCCUtil(long long int u, long long int disc[], long long int low[], stack<long long int> *st,bool stackMember[])
{
	static long long int time = 0;

	disc[u] = low[u] = ++time;
	st->push(u);
	stackMember[u] = true;

	vector<long long int>::iterator i;
	for (i = adj[u].begin(); i != adj[u].end(); ++i)
	{
		long long int v = *i; 

		if (disc[v] == -1)
		{
			SCCUtil(v, disc, low, st, stackMember);
			low[u] = min(low[u], low[v]);
		}
		else if (stackMember[v] == true)
			low[u] = min(low[u], disc[v]);
	}

	long long int w = 0; 
	if (low[u] == disc[u])
	{
		multiset<long long int> ms;
		while (st->top() != u)
		{
			w = (long long int) st->top();
			//cout << w << " ";
			ms.insert(arr[w]);
			stackMember[w] = false;
			st->pop();
		}
		w = (long long int) st->top();
		//cout << w << "\n";
		ms.insert(arr[w]);
		multiset<long long int>::iterator msiter;
		msiter=ms.begin();
		sum += *msiter;
		pro = ( pro * ms.count(*msiter) )%mod	;
		stackMember[w] = false;
		st->pop();
	}
}

void Graph::SCC()
{
	long long int *disc = new long long int[V];
	long long int *low = new long long int[V];
	bool *stackMember = new bool[V];
	stack<long long int> *st = new stack<long long int>();

	for (long long int i = 0; i < V; i++)
	{
		disc[i] = NIL;
		low[i] = NIL;
		stackMember[i] = false;
	}

	for (long long int i = 0; i < V; i++)
		if (disc[i] == NIL)
			SCCUtil(i, disc, low, st, stackMember);
}
//0 indexed. So decrement node numbers by one.

int main()
{

	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,m,u,v,i;
	
	cin>>n;
	for(i=0;i<n;i++)
		cin>>arr[i];
	
	Graph g(n);
	
	cin>>m;
	
	
	for(i=0;i<m;i++)
	{
		cin>>u>>v;
		u--;
		v--;
		g.addEdge(u,v);
	}
	
	g.SCC();
	
	
	cout<<sum<<" "<<pro;
	return 0;
}
