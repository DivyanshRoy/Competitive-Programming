// Problem Link: https://www.spoj.com/problems/SPATTERN/

#include <bits/stdc++.h>
using namespace std;
#define mod 10000009
bool b[70];
long long int arr[70];
 
void calc(long long int x,long long int n)
{
	long long int i=1,val=1;
	for(i=1;i<=n;i++)
	{
		arr[i]=val;
		val=(val*x)%mod;
	}
}
 
int main() {
	long long int mx,t,i,n,x,tmp,lg,nlg,val;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld %lld",&x,&n);
		if(x==0)
		{
			printf("0\n");
			continue;
		}
		if(x==1)
		{
			if(n==0)
				printf("0\n");
			else
				printf("1\n");
			continue;
		}
		x%=mod;
		for(i=0;i<=65;i++)
			b[i]=0;
		i=1;
		mx=0;
		tmp=n;
		while(n>0)
		{
			if(n%2==1)
			{
				b[i]=1;
				mx=max(mx,i);
			}
			else
				b[i]=0;
			n>>=1;
			i++;
		}
		calc(x,mx);
 
		n=tmp;
		val=0;
	/*	while(n>0)
		{
			lg=log(n)/log(2);
			nlg=1<<lg;
			n-=nlg;
			val=(val+arr[lg+1])%mod;
		}
	*/	
		
		for(i=0;i<=mx;i++)
		{
			if(b[i])
				val=(val+arr[i])%mod;
		}
		
		printf("%lld\n",val);
	}
	return 0;
} 