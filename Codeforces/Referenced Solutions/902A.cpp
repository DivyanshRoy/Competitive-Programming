// Problem Link: https://codeforces.com/contest/902/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	int n,m,i,a,b,mx=0;
	
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
	{
		cin>>a>>b;
		if(mx>=a)
			mx=max(mx,b);
	}
	if(mx>=m)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}   