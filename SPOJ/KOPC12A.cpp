// Problem Link: https://www.spoj.com/problems/KOPC12A/

#include <bits/stdc++.h>
using namespace std;
 
long long int h[10005],c[10005],n;
 
long long int calc(long long int val)
{
	long long int i,sum=0;
	for(i=1;i<=n;i++)
	{
		if(h[i]>val)
		{
			sum+=(h[i]-val)*c[i];
		}
		else
			sum+=(val-h[i])*c[i];
	}
	return sum;
}
 
long long int bs(long long int mn,long long int mx)
{
	long long int v1,v2,lo,hi,mid,m1,m2;
	lo=mn;
	hi=mx;
	
	m1=lo;
	m2=hi;
	while(m1<m2)
	{
		v1=calc(m1);
		v2=calc(m2);
		if(v1<v2)
		{
			hi=m2-1;
		}
		else
		{
			lo=m1+1;
		}
	
		//m1=(lo+mid)/2;
		m1=lo+(hi-lo)/3;
		m2=hi-(hi-lo)/3;
		//m2=(mid+hi)/2;
	}
	return v1<v2?v1:v2;
}
 
int main() {
	long long int t,i,mn,mx;
	scanf("%lld",&t);
	while(t--)
	{
		mn=1000000;
		mx=0;
		scanf("%lld",&n);
		for(i=1;i<=n;i++)
		{
			scanf("%lld",&h[i]);
			mn=min(mn,h[i]);
			mx=max(mx,h[i]);
		}
		for(i=1;i<=n;i++)
		scanf("%lld",&c[i]);
		printf("%lld\n",bs(mn,mx));
	}
	return 0;
} 