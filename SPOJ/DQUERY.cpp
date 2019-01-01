// Problem Link: https://www.spoj.com/problems/DQUERY/

#include <bits/stdc++.h>
using namespace std;
 
long int arr[30005],n,q;
vector< pair< pair<long int,long int> , long int> > p; // left , right , index
long int ans[200005],pre[1000005];
long int table[30005];
 
bool cmp(pair< pair<long int,long int> , long int> a,pair< pair<long int,long int> , long int> b)
{
	if((a.first).second!=(b.first).second)
		return (a.first).second<(b.first).second;
	return (a.first).first<(b.first).first;
}
 
void update(long int i,long int v)
{
	long int j=i;
	while(j<=n)
	{
		table[j]+=v;
		j+=j&-j;
	}
}
 
long int ret(long int n)
{
	long int sum=0;
	while(n>0)
	{
		sum+=table[n];
		n-=n&-n;
	}
	return sum;
}
 
int main() {
	scanf("%ld",&n);
	long int i,l,r;
	for(i=1;i<=n;i++)
	{
		scanf("%ld",&arr[i]);
		table[i]=0;
	}
	scanf("%ld",&q);
	p.resize(q+1);
	for(i=1;i<=q;i++)
	{
		scanf("%ld %ld",&l,&r);
		p[i]=make_pair(make_pair(l,r),i);
	}
	sort(p.begin(),p.end(),cmp);
	for(i=1;i<=1000000;i++)
	{
		pre[i]=-1;
	}
	long int id=1;
	
	for(i=1;i<=n;i++)
	{
		if(pre[arr[i]]!=-1)
		{
			update(pre[arr[i]],-1);
		}
		update(i,1);
		pre[arr[i]]=i;
		while(p[id].first.second==i&&id<=q)
		{
			ans[p[id].second]=ret(p[id].first.second)-ret(p[id].first.first-1);
			id++;
		}
	}
	for(i=1;i<=q;i++)
	printf("%ld\n",ans[i]);
	return 0;
} 