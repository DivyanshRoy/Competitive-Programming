// Problem Link: https://codeforces.com/contest/934/problem/A

#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	long long int n,m,a[100],b[100],i,j,ans=1000000000000000009,k;
	
	cin>>n>>m;
	
	for(i=0;i<n;i++)
		cin>>a[i];
	
	for(i=0;i<m;i++)
		cin>>b[i];
	
	for(i=0;i<n;i++)
	{
		long long int ta=-1000000000000000009;
		for(j=0;j<n;j++)
		{
			if(i==j)
				continue;
			for(k=0;k<m;k++)
			{
				ta=max(ta,a[j]*b[k]);
			}
		}
		ans=min(ans,ta);
	}
	
	cout<<ans;
	
	return 0;
}