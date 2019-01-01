// Problem Link: https://www.spoj.com/problems/QN02/

#include<bits/stdc++.h>
using namespace std;
 
long int len[100005],root[100005];
 
long int froot(long int a)
{
	while(a!=root[a])
		a=root[a];
	return a;
}
 
void uni(long int a,long int b)
{
	long int ra,rb;
	ra=froot(a);
	rb=froot(b);
	if(ra==rb)
		return;
	if(len[ra]>len[rb])
	{
		root[rb]=ra;
		len[ra]+=len[rb];
	}
	else
	{
		root[ra]=rb;
		len[rb]+=len[ra];
	}
}
 
int main()
{
	long int n,m,i,q,a,b;
	scanf("%ld %ld",&n,&m);
	for(i=1;i<=n;i++)
	{
		len[i]=1;
		root[i]=i;
	}
	for(i=1;i<=m;i++)
	{
		scanf("%ld %ld",&a,&b);
		a++;
		b++;
		uni(a,b);
	}
	scanf("%ld",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%ld %ld",&a,&b);
		a++;
		b++;
		if(froot(a)==froot(b))
			printf("YES\n");
		else
			printf("NO\n");
	}
} 