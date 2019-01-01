// Problem Link: https://www.codechef.com/problems/MATPAN

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long int t,n,cost[30],i,ans,is[30];
	char arr[50005];
	cin>>t;
	while(t--)
	{
		for(i=0;i<26;i++)
		{
			cin>>cost[i];
			is[i]=0;
		}
		cin>>arr;
		n=strlen(arr);
		for(i=0;i<n;i++)
		{
			is[arr[i]-'a']=1;
		}
		ans=0;
		for(i=0;i<26;i++)
		{
			if(!is[i])
				ans+=cost[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}