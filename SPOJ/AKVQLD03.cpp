// Problem Link: https://www.spoj.com/problems/AKVQLD03/

#include <bits/stdc++.h>
using namespace std;
 
long int n,table[1000005];
 
void update(long int i,long int v)
{
	while(i<=n)
	{
		table[i]+=v;
		i+=i&-i;
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
	long int i,l,r,q;
	char arr[10];
	scanf("%ld %ld",&n,&q);
	for(i=1;i<=n;i++)
	{
		table[i]=0;
	}
	for(i=1;i<=q;i++)
	{
		scanf("%s %ld %ld",arr,&l,&r);
		if(arr[0]=='a')
		{
			update(l,r);
		}
		else
			printf("%ld\n",ret(r)-ret(l-1));
	}
	return 0;
} 