// Problem Link: https://codeforces.com/contest/932/problem/A

#include <bits/stdc++.h>
using namespace std;


int main()
{
	
	char a[10005],b[10005];
	int len,i,j;
	
	cin>>a;
	
	len=strlen(a);
	j=0;
	for(i=0;i<len;i++,j++)
	{
		b[j]=a[i];	
	}	
	for(i=len-1;i>=0;i--,j++)
	{
		b[j]=a[i];	
	}	
	for(i=0;i<(len*2);i++)
		cout<<b[i];
	
	return 0;
}