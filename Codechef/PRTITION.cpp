// Problem Link: https://www.codechef.com/JAN18/problems/PRTITION

#include<bits/stdc++.h>
using namespace std;
#define MAX 1000005

int group[MAX];

int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int t,n,x,i,val,l,r;
	
	cin>>t;
	
	while(t--)
	{
		cin>>x>>n;
		
		if((((n*(n+1))/2)-x)&1)
		{
			cout<<"impossible\n";
			continue;
		}
		else if(n==2||n==3)
		{
			cout<<"impossible\n";
			continue;
		}
		
		
		for(i=1;i<=n;i++)
			group[i]=0;
		
		
		group[x]=2;
		
		val=(n*(n+1))/2;
		val-=x;
		val/=2;
		
		r=n;
		while(val>0)
		{
			r=min(r,val);
			if(r==x)
			{
				r--;
				continue;
			}
			if(val<=MAX)
			{
				if(group[val-r]==2&&(val-r)<=2)
				{
					r--;
					continue;
				}
			}
			//cout<<r<<" "<<val<<endl;
			val-=r;
			group[r]=1;
			r--;
		}
		
		for(i=1;i<=n;i++)
			cout<<group[i];
		cout<<endl;
	}

	return 0;
}