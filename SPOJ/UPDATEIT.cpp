// Problem Link: https://www.spoj.com/problems/UPDATEIT/

#include <bits/stdc++.h>
using namespace std;
 
long int arr[10005],table[10005],n;
 
void update(long int i,long int v)
{
	long int j=i;
	while(j<=n)
	{
		table[j]+=v;
		j+=j&-j;
	}
}
 
long int ret(long int i)
{
	long int sum=0;
	while(i>0)
	{
		sum+=table[i];
		i-=i&-i;
	}
	return sum;
}
 
int main() {
	long int l,r,q,i,u,v,t;
	scanf("%ld",&t);
	while(t--){
	scanf("%ld %ld",&n,&u);
for(i=1;i<=n;i++)
{
table[i]=0;
}
	for(i=1;i<=u;i++)
	{
		scanf("%ld %ld %ld",&l,&r,&v);
		l++;
		r++;
		update(l,v);
		update(r+1,v*-1);
	}
	scanf("%ld",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%ld",&l);
		l++;
		printf("%ld\n",ret(l));
	}
	}
	return 0;
} 