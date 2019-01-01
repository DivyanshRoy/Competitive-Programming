// Problem Link: https://codeforces.com/contest/939/problem/B

#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long int n,k,i,arr[100005],mn,ind,num;
	ind=0;
	mn=1000000000000000009LL;
	
	cin>>n>>k;
	
	for(i=1;i<=k;i++)
	{
		cin>>arr[i];
		
		num=n-((n/arr[i])*arr[i]);
		if(num<mn)
		{
			mn=num;
			ind=i;
		}
	}
	cout<<ind<<" "<<n/arr[ind];
	return 0;
}