// Problem Link: https://www.codechef.com/JAN18/problems/MAXSC

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005


int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int t,n,i,j,ans=0,pmax=1000000009LL,x;
	vector<long long int> vec[1000];


	cin>>t;
	
	while(t--)
	{
		cin>>n;
		ans=0;
		pmax=1000000009LL;
		
		for(i=0;i<1000;i++)
			vec[i].clear();
			
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				cin>>x;
				vec[i].push_back(x);
			}
		}
		
		for(i=0;i<n;i++)
			sort(vec[i].begin(),vec[i].end());
		bool no=0;
		for(i=n-1;i>=0;i--)
		{
			for(j=n-1;j>=0;j--)
			{
				if(vec[i][j]<pmax)
				{
					pmax=vec[i][j];
					ans+=vec[i][j];
					break;
				}
			}
			if(j==-1)
			{
				no=1;
				break;
			}
		}
		if(no)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}

	return 0;
}