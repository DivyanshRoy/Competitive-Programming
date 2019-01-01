// Problem Link: https://www.codechef.com/DEC17/problems/DSANTAP

#include<bits/stdc++.h>
using namespace std;
 
long long int n,g,b,x[1000],y[1000],pre[1000],cur[1000],dist[1000][1000],vis[1000],wt[1000];
  
void visit(long long int a)
{
	long long int i;
	cout<<"3 "<<cur[a]<<endl;
	cout<<"2 "<<pre[a]<<endl;
	vis[a]=1;
	
	long long int ind=-1;
	for(i=1;i<=n;i++)
	{
		if(!vis[i]&&cur[i]==pre[a])
		{
			if(ind==-1)
			{
				ind=i;
			}
			else if(dist[a][i]<dist[a][ind])
			{
				ind=i;
			}
		}
	}
	if(ind!=-1)
	{
		cout<<"1 "<<ind<<endl;
		visit(ind);
		return;
	}
	cout<<"1 0"<<endl;
	cout<<"3 "<<pre[a]<<endl;
	
}
  
void visitFromHome(long long int a)
{
	long long int i;
	cout<<"2 "<<cur[a]<<endl;
	cout<<"1 "<<a<<endl;
	cout<<"3 "<<cur[a]<<endl;
	cout<<"2 "<<pre[a]<<endl;
	vis[a]=1;
	long long int ind=-1;
	for(i=1;i<=n;i++)
	{
		if(!vis[i]&&cur[i]==pre[a])
		{
			if(ind==-1)
			{
				ind=i;
			}
			else if(dist[a][i]<dist[a][ind])
			{
				ind=i;
			}
		}
	}
	if(ind!=-1)
	{
		cout<<"1 "<<ind<<endl;
		visit(ind);
		return;
	}
	cout<<"1 0"<<endl;
	cout<<"3 "<<pre[a]<<endl;
}
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	long long int t,i,j;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>g>>b>>x[0]>>y[0];
		for(i=1;i<=g;i++)
			cin>>wt[i];
		for(i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i]>>pre[i]>>cur[i];	
			vis[i]=0;
		}	
		
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=n;j++)
			{
				dist[i][j] = (x[i]-x[j])*(x[i]-x[j]) + (y[i]-y[j])*(y[i]-y[j]);
			}
		}
		
		for(i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				visitFromHome(i);
			}
		}
		cout<<0<<endl;
	}	
	
	return 0;
}   