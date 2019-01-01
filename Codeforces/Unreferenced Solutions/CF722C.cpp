#include <bits/stdc++.h>
using namespace std;

long int mx=0,n,arr[100001],root[100001],len[100001],sum[100001],order[100001];
bool b[100001];

long int froot(long int a)
{
	if(a!=root[a])
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
		root[rb]=root[ra];
		len[ra]+=len[rb];
		sum[ra]+=sum[rb];
		if(sum[ra]>mx)
		mx=sum[ra];
	}
	else
	{
		root[ra]=root[rb];
		len[rb]+=len[ra];
		sum[rb]+=sum[ra];
		if(sum[rb]>mx)
		mx=sum[rb];
	}
}

void calc(long int a)
{
	b[a]=1;
	mx=max(mx,arr[a]);
	if(a>1&&a<n)
	{
		if(b[a-1])
		uni(a,a-1);
		if(b[a+1])
		uni(a,a+1);
	}
	else if(a>1)
	{
		if(b[a-1])
		uni(a,a-1);
	}
	else if(a<n)
	{
		if(b[a+1])
		uni(a,a+1);
	}

}

int main()
{
	long int i;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&arr[i]);
		sum[i]=arr[i];
		b[i]=0;
		len[i]=1;
		root[i]=i;
	}
	for(i=1;i<=n;i++)
		scanf("%ld",&order[i]);
	long int out[n+1];
	out[n]=0;
	calc(order[n]);
	for(i=n-1;i>0;i--)
	{
		out[i]=mx;
		calc(order[i]);
	}
	for(i=1;i<=n;i++)
	cout<<out[i]<<endl;
	return 0;
}
