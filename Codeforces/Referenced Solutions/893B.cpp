// Problem Link: https://codeforces.com/contest/893/problem/B

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

bool is[MAX];

int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int i,n,m=1,a=2,ans=0,sq;
	for(i=0;i<MAX;i++)
		is[i]=0;
	while(1)
	{
		i=(m*(a-1));
		m*=2;
		a*=2;
		if(i>MAX-3)
			break;
		is[i]=1;
	}
	
	cin>>n;
	sq=sqrt(n);
	for(i=1;i<=n;i++)
	{
		if(n%i==0)
		{
			if(is[i])
				ans=max(ans,i);
		}
	}
	cout<<ans;
	return 0;
}