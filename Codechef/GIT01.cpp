// Problem Link: https://www.codechef.com/DEC17/problems/GIT01

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
 
	long long int t,n,m,i,j,ta,ans;
	char arr[105][105];
	
	cin>>t;
	
	while(t--)
	{
		cin>>n>>m;
		for(i=0;i<n;i++)
			cin>>arr[i];
		
		ans=100000000;
		
		ta=0;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]=='R'&&((i+j)%2)==0)
					ta+=5;
				if(arr[i][j]=='G'&&((i+j)%2)==1)
					ta+=3;
			}
		}
		
		ans=min(ans,ta);
		
		ta=0;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]=='G'&&((i+j)%2)==0)
					ta+=3;
				if(arr[i][j]=='R'&&((i+j)%2)==1)
					ta+=5;
			}
		}
		
		ans=min(ans,ta);
		cout<<ans<<endl;
	}

	return 0;
}  