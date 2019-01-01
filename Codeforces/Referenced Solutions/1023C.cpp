// Problem Link: https://codeforces.com/contest/1023/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005

int main()
{
	
	long long int n,k,ob,left,i;
	char arr[MAX];
	cin>>n>>k;
	
	cin>>arr;
	ob=0;
	left = k;
	
	for(i=0;i<n;i++)
	{
		if(ob==left)
			break;
		if(arr[i]=='(')
			ob++;
		else
			ob--;
		cout<<arr[i];
		left--;
	}
	for(i=0;i<left;i++)
		cout<<")";
	
	return 0;
}