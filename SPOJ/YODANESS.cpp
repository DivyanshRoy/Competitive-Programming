// Problem Link: https://www.spoj.com/problems/YODANESS/

#include <bits/stdc++.h>
using namespace std;
 
long long int t,n,arr[200005],bit[200005],sor[200005],occ[200005];
unordered_map<string,long int> ma;
 
void update(long long int i)
{
	long long int j=i;
	while(j<=n)
	{
		bit[j]++;
		j+=j&-j;
	}
}
 
long long int sum(long long int n)
{
	long long int s,j;
	s=0;
	j=n;
	while(j>0)
	{
		s+=bit[j];
		j-=j&-j;
	}
	return s;
}
 
int main() {
	long long int i,x;
	string str;
	cin>>t;
	while(t--)
	{
		ma.clear();
		cin>>n;
		for(i=1;i<=n;i++)
		{
			bit[i]=0;
			occ[i]=0;
			cin>>str;
			ma[str]=i;
		}
		long long int cnt=0,pos;
		string nstr[30005];
		for(i=1;i<=n;i++)
		{
			cin>>nstr[i];
		}
		for(i=n;i>=1;i--)
		{
			pos=ma[nstr[i]];
			cnt+=sum(pos)-occ[pos];
			update(pos);
			occ[pos]++;
		}
		cout<<cnt<<endl;
	}
	return 0;
} 