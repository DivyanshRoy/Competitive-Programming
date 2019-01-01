// Problem Link: https://codeforces.com/contest/1017/problem/B

#include<bits/stdc++.h>
using namespace std;
#define mx 100005


int main()
{
	
	long long int n,i,c0,c1,ans=0;
	char a[mx],b[mx];
	c0 = c1 = 0;
	cin>>n;
	cin>>a;
	cin>>b;
	for(i=0;i<n;i++)
	{
		if(a[i]=='0')
			c0++;
		else
			c1++;
	}
	
	for(i=0;i<n;i++)
	{
		if(b[i]=='0')
		{
			if(a[i]=='0')
			{
				ans+=c1;
				c0--;
			}
			else
			{
				ans+=c0;
				c1--;
			}
			
		}
	}
	cout<<ans;
	return 0;
}