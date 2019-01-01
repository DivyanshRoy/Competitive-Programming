// Problem Link: https://codeforces.com/contest/898/problem/D

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	long long int i,n,m,k,arr[MAX],ans=0,l=0,sub=0;
	bool mark[MAX];
	
	
	cin>>n>>m>>k;
	l=1;
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
		mark[i]=0;
	}
	sort(arr+1,arr+n+1);
	for(i=1;i<=n;i++)
	{
		while((arr[i]-arr[l])>=m)
		{
			if(mark[l])
				sub--;
			l++;
		}
		if((i-l-sub+1)==k)
		{
			ans++;
			mark[i]=1;
			sub++;
		}
	}
	cout<<ans;
	return 0;
}   