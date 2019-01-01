// Problem Link: https://codeforces.com/contest/893/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

long long int dsu_par[MAX],dsu_size[MAX],dsu_min[MAX];


void dsu_initialize(long long int N)
{
    for(long long int i = 0;i<N;i++)
    {
        dsu_par[i] = i ;
        dsu_size[i] = 1;
        dsu_min[i]=1000000007;
    }
}


//Parent Array name is dsu_par
long long int dsu_root (long long int i)
{
    while(dsu_par[i] != i)
    {
        dsu_par[i] = dsu_par[ dsu_par[i] ] ; 
        i = dsu_par[i]; 
    }
    return i;
}

//Parent Array name is dsu_par and Size array name is dsu_size
void dsu_union(long long int A,long long int B)
{
    long long int root_A = dsu_root(A);
    long long int root_B = dsu_root(B);
    if(dsu_size[root_A] < dsu_size[root_B ])
    {
        dsu_par[root_A] = dsu_par[root_B];
        dsu_size[root_B] += dsu_size[root_A];
        dsu_min[root_B]=min(dsu_min[root_A],dsu_min[root_B]);
    }
    else
    {
        dsu_par[root_B] = dsu_par[root_A];
        dsu_size[root_A] += dsu_size[root_B];
        dsu_min[root_A]=min(dsu_min[root_A],dsu_min[root_B]);
    }
}

//Returns true if A and B are in same Set
bool dsu_find(long long int A,long long int B)
{
    if(dsu_root(A)==dsu_root(B))
        return true;
    else
        return false;
}

int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,m,arr[MAX],i,u,v,ans=0;
	cin>>n>>m;
	dsu_initialize(MAX);
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
		dsu_min[i]=arr[i];
	}
	for(i=1;i<=m;i++)
	{
		cin>>u>>v;
		dsu_union(u,v);
	}
	set<long long int> se;
	for(i=1;i<=n;i++)
	{
		se.insert(dsu_root(i));
	}
	set<long long int>::iterator iter;
	for(iter=se.begin();iter!=se.end();iter++)
	{
		ans+=dsu_min[*iter];
	}
	cout<<ans;
	return 0;
}