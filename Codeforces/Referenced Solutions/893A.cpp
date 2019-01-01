// Problem Link: https://codeforces.com/contest/893/problem/A

#include<bits/stdc++.h>
using namespace std;


int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,i,p1,p2,s,w;
	p1=1;
	p2=2;
	s=3;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>w;
		if(s==w)
		{
			cout<<"NO";
			return 0;
		}
		if(w==p1)
			swap(p2,s);
		else
			swap(p1,s);
	}
	cout<<"YES";
	return 0;
}