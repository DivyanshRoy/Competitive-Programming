// Problem Link: https://www.spoj.com/problems/NR2/

#include <bits/stdc++.h>
using namespace std;
 
long long int bits[61];
 
void calc(long long int n)
{
	long long int i=1;
	while(n>0)
	{
		if(n%2==1)
			bits[i]++;
		n>>=1;
		i++;
	}
}
 
int main() {
	long long int n,i,v;
	for(i=1;i<=60;i++)
	bits[i]=0;
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&v);
		calc(v);
	}
	long long int add,cnt=0;
	for(i=1;i<=60;i++)
	{
		if(bits[i]>0&&bits[i]<n)
		{
			add=pow(2,i-1);
			cnt+=add;
		}
	}
	printf("%lld",cnt);
	return 0;
} 