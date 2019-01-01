// Problem Link: https://codeforces.com/contest/939/problem/A

#include <bits/stdc++.h>
using namespace std;

int main()
{

	long long int n,i,arr[10000];
	bool yes=0;
	cin>>n;
	
	for(i=1;i<=n;i++)
		cin>>arr[i];
		
	for(i=1;i<=n;i++)
	{
		if(arr[arr[arr[i]]]==i)
			yes=1;
	}
	if(yes)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}