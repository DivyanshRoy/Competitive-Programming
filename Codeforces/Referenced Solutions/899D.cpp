// Problem Link: https://codeforces.com/contest/899/problem/D

#include<bits/stdc++.h>
using namespace std;

int main()
{
	
	long long int n,d,tmp,cnt,num=1,ans=0,changer,adder;
	
	cin>>n;
	if(n<5)
	{
		cout<<((n)*(n-1))/2;
		return 0;
	}
	d=0;
	
	tmp=n*2;
	
	while(tmp>=10)
	{
		d++;
		tmp/=10;
		num*=10;
	}
	for(long long int i=0;i<10;i++)
	{
		if(n==((num-1)+(i*num)))
			ans--;
	}
	cnt=n/num;
	
	{
		ans+=(cnt*cnt*5)*num/10;	
		n-=cnt*num;
		adder=cnt;
		changer=5*num/10;
		if(n>=changer)
		{
			ans+=(5*cnt*num)/10;
			ans++;
			n-=changer;	
			adder++;
		}	
		while(n!=0)
		{
			ans+=adder;
			n--;
		}
	}
	cout<<ans;
	return 0;
}