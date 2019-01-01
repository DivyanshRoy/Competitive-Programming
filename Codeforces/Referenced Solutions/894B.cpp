// Problem Link: https://codeforces.com/contest/894/problem/B

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int powe(long long int a, long long int b)
{
	long long int m=mod;
	long long int ret = 1;
	while (b)
	{
		if (b & 1) ret = (ret*a)%m;
		a = (a*a) %m;
		b >>= 1;
	}
	return ret;
}


int main()
{

	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int a,b;
	long long int n,m,k;
		
	cin>>n>>m>>k;
	
	if(n==1||m==1)
	{
		if(k==1)
			cout<<1;
		else
		{
			if(max(n,m)%2==1)
				cout<<1;
			else
				cout<<0;
		}
		return 0;
	}

	if(k==-1 && ( (n%2==1&&m%2==0) || (n%2==0&&m%2==1) ) )
	{
		cout<<0;
		return 0;
	}
		
	long long int ans,ta=powe(2,n-1),tb=powe(ta,m-1);
	ans=tb;
	cout<<ans;
	return 0;
}