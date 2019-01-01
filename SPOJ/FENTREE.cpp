// Problem Link: https://www.spoj.com/problems/FENTREE/

#include <bits/stdc++.h>
using namespace std;
 
long int arr[1000005],table[1000005],n;
 
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
	long int l,r,q,i;
	char c;
	scanf("%ld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&arr[i]);
		update(i,arr[i]);
	}
	scanf("%ld",&q);
	for(i=1;i<=q;i++)
	{
		cin>>c;
		scanf("%ld %ld",&l,&r);
		if(c=='q')
		{
			printf("%ld\n",(ret(r)-ret(l-1)));
		}
		else
			update(l,r);
	}
	return 0;
} 