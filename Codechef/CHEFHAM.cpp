// Problem Link: https://www.codechef.com/DEC17/problems/CHEFHAM

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
 
	long long int t,a[MAX],b[MAX],i,n;
	pair<long long int,long long int> p[MAX];
 
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			p[i]={a[i],i};
		}
		if(n==1)
		{
			cout<<0<<endl;
			cout<<a[0]<<endl;
			continue;
		}
		else if(n==2)
		{
			if(a[0]==a[1])
				cout<<0<<endl;
			else
				cout<<2<<endl;
			swap(a[0],a[1]);
			cout<<a[0]<<" "<<a[1]<<endl;
			continue;
		}
		sort(p,p+n);
		
		for(i=0;i<n;i++)
		{
			b[p[i].second]=p[(i+2)%n].first;
		}
		long long int cnt=0;
		
		for(i=0;i<n;i++)
		{
			if(a[i]!=b[i])
				cnt++;
		}
		cout<<cnt<<endl;
		for(i=0;i<n;i++)
			cout<<b[i]<<" ";
		cout<<endl;
	}
 
	return 0;
}  