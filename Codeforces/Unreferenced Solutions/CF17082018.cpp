#include<bits/stdc++.h>
using namespace std;
#define MAX 200005

set<long long int> se;
int done[MAX];


void remove(long long int m)
{
	set<long long int>::reverse_iterator riter;
	vector<long long int> del;
	for(riter=se.rbegin();riter!=se.rend();riter++)
	{
		long long int x = *riter;
		if(x<=m)
			break;
		done[x]=1;
		del.push_back(x);
	}
	vector<long long int>::iterator iter;
	for(iter=del.begin();iter!=del.end();iter++)
	{
		se.erase(*iter);
	}
}

void add(long long int m)
{
	se.insert(m);
}


int main()
{
	
	long long int n,q,i,arr[MAX];
	
	for(i=0;i<MAX;i++)
		done[i]=0;
		
	cin>>n>>q;
	for(i=0;i<n;i++)
		cin>>arr[i];
	arr[n]=-1;
	int valid=1;
	for(i=0;i<n;i++)
	{
		if(done[arr[i]]==1&&arr[i]>0)
		{
			valid=0;
			break;
		}
		if(arr[i]>0)
		{
			add(arr[i]);
			remove(arr[i]);	
		}
	}
	
	if(!valid)
	{
		cout<<"NO";
	}
	else
	{
		long long int mx=0;
		for(i=0;i<n;i++)
		{
			mx = max(mx,arr[i]);
		}
		if(mx==0)
		{
			for(i=0;i<n-1;i++)
				arr[i]=1;
			arr[n-1]=q;
			cout<<"YES\n";
			for(i=0;i<n;i++)
				cout<<arr[i]<<" ";
		}
		else if(mx!=q)
		{
			long long int fi=-1;
			
			for(i=0;i<n;i++)
			{
				if(arr[i]==0)
				{
					fi=i;
					break;
				}
			}
			
			if(fi==-1)
			{
				cout<<"NO";
			}
			else
			{
				arr[fi]=q;
				for(i=fi+1;i<n;i++)
				{
					if(arr[i]==0)
						arr[i]=max(arr[i-1],arr[i+1]);
				}
				cout<<"YES\n";
				for(i=0;i<n;i++)
					cout<<arr[i]<<" ";
			}
		}
		else
		{
			for(i=0;i<n;i++)
			{
				if(arr[i]==0)
					arr[i]=max(arr[i-1],arr[i+1]);
			}
			cout<<"YES\n";
			for(i=0;i<n;i++)
				cout<<arr[i]<<" ";
		}
	}
	
	return 0;
}
