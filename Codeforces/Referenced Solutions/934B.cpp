// Problem Link: https://codeforces.com/contest/934/problem/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
	
	long long int n,i;
	
	cin>>n;
	
	if(n>36)
	{
		cout<<"-1";
		return 0;
	}
	
	for(i=0;i<n/2;i++)
		cout<<8;
	if(n&1)
		cout<<6;
	
	return 0;
}