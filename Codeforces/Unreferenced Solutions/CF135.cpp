#include<bits/stdc++.h>
using namespace std;
#define mx 100005


int main()
{
	
	long long int n,i,a,b,c,d,s0,s1,ans;
	cin>>n;
	
	cin>>a>>b>>c>>d;
	s0 = a+b+c+d;
	ans = 0;
	
	for(i=1;i<n;i++)
	{
		cin>>a>>b>>c>>d;
		s1 = a+b+c+d;
		if(s1>s0)
			ans++;
	}
	cout<<ans+1;
	return 0;
}
