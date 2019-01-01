// Problem Link: https://codeforces.com/contest/899/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	long long int n,i;
	cin>>n;
	
	if(n%4==0)
	{
		cout<<0<<endl;
		cout<<n/2<<" ";
		for(i=1;i<=n/2;i+=2)
		{
			cout<<i<<" "<<n-i+1<<" ";
		}
	}
	else if(n%2==0)
	{
		cout<<1<<endl;
		cout<<n/2<<" ";
		for(i=1;i<=n/2;i+=2)
		{
			if(i==n/2)
				cout<<i<<" ";
			else
			cout<<i<<" "<<n-i+1<<" ";
		}
	}
	else
	{
		if((n+1)%4==0)
		{
			cout<<0<<endl;
			cout<<(n/2)+1<<" ";
			cout<<1<<" "<<2<<" ";
			for(i=1;i<=((n-3)/2);i+=2)
			{
				cout<<i+3<<" "<<n-i+1<<" ";
			}
			return 0;
		}
		else
		{
			cout<<1<<endl;
		
			cout<<n/2<<" ";
		}
		
		for(i=2;i<=n/2;i+=2)
		{
			cout<<i<<" "<<((n+1)/2)+i<<" ";
		}
	}
	
	return 0;
}   