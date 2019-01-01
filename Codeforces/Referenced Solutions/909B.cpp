// Problem Link: https://codeforces.com/contest/909/problem/B

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long int cnt[200],i,j,k,n,ans=0;
	
	for(i=0;i<200;i++)
		cnt[i]=0;

	cin>>n;
	
	for(i=0;i<=n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			for(k=i;k<j;k++)
			{
				cnt[k]++;
			}
		}
	}
	
	for(i=0;i<=n;i++)
		ans=max(ans,cnt[i]);
	cout<<ans;

	return 0;
}