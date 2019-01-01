#include<bits/stdc++.h>
using namespace std;

long long int ans[10005],i,j;

void calc()
{
	long long int sq;
	for(i=0;i<10005;i++)
	{
		ans[i]=1000000007;
	}
	ans[0]=0;
	for(i=0;i<=10000;i++)
	{
		for(j=1;j<=100;j++)
		{
			sq=j*j;
			if(i+sq>10000)
				break;
			ans[i+sq]=min(ans[i+sq],ans[i]+1);
		}
	}
}

int main()
{
	freopen("D-large.in","r",stdin);
    freopen("output.txt","w",stdout);
	calc();
	long long int t,n,j;
	cin>>t;
	j=1;
	while(j<=t)
	{
		cin>>n;
		cout<<"Case #"<<j<<": "<<ans[n]<<endl;
		j++;
	}
    return 0;
}

