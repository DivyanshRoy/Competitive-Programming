// Problem Link: https://codeforces.com/contest/1023/problem/B

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005

int main()
{
	
	long long int n,k,h,l,r,cl,cr,ans;
	
	cin>>n>>k;
	
	h = k/2;
	
	if(2*h==k)
	{
		l = h-1;
		r = h+1;
	}
	else
	{
		l = h;
		r = h+1;
	}
	
	cl = l;
	cr = n-r+1;
	ans = min(cl,cr);
	ans = max(ans,0LL);
	cout<<ans;
	
	return 0;
}