// Problem Link: https://codeforces.com/contest/899/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	long long int n,arr,one,two,i,ans=0;
	one=two=0;
	
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cin>>arr;
		if(arr==1)
			one++;
		else
			two++;
	}
	
	ans+=min(one,two);
	one-=ans;
	ans+=(one/3);
	cout<<ans;
	return 0;
}   