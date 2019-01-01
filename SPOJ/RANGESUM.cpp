// Problem Link: https://www.spoj.com/problems/RANGESUM/

#include <bits/stdc++.h>
using namespace std;
 
long int tn,n,nu,nq;
long long int table[200005];
 
void update(long int i,long int v)
{
	while(i<=tn)
	{
		table[i]+=v;
		i+=i&-i;
	}
}
 
long long int ret(long int i)
{
	long long int sum=0;
	while(i>0)
	{
		sum+=table[i];
		i-=i&-i;
	}
	return sum;
}
 
int main() {
	long int i,q,l,r,c;
	scanf("%ld",&n);
	long int arr1[100005],arr2[100005];
	vector< pair<long int,long int> > vec;
	for(i=1;i<=n;i++)
		scanf("%ld",&arr1[i]);
	nu=nq=0;
	scanf("%ld",&q);
	for(i=1;i<=q;i++)
	{
		scanf("%ld",&c);
		if(c==1)
		{
			nq++;
			scanf("%ld %ld",&l,&r);
			vec.push_back(make_pair(l-nu,r-nu));
		}
		else
		{
			nu++;
			scanf("%ld",&l);
			arr2[nu]=l;
		}
	}
	tn=n+nu;
	long int cnt=1;
	for(i=nu;i>=1;i--,cnt++)
		update(cnt,arr2[i]);
	for(i=1;i<=n;i++,cnt++)
	{
		update(cnt,arr1[i]);
	}
	vector< pair<long int,long int> >::iterator iter;
	for(iter=vec.begin();iter!=vec.end();iter++)
	{
		printf("%lld\n",ret(nu+iter->second)-ret(nu+iter->first-1));
	}
	return 0;
} 