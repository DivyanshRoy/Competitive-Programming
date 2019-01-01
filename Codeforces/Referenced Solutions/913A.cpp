// Problem Link: https://codeforces.com/contest/913/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005

long long int fast_pow(long long int a,long long int p,long long int m)
{
	if(p==0)
		return 1;
	if(p==1)
		return a;
	long long int ans=1,sq=fast_pow(a,p/2,m);
	if(sq==-1)
		return -1;
	ans=(sq*sq);
	if(p&1)
		ans=(ans*a);
	if(ans>m)
		return -1;
	return ans;
}


int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,m,p;
	
	cin>>n>>m;
	
	p=fast_pow(2LL,n,m);
	
	if(p==-1)
		cout<<m;
	else
		cout<<m%p;

	return 0;
}