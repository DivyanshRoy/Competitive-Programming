// Problem Link: https://codeforces.com/contest/898/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	long long int n,d,rest;
	
	cin>>n;
	d=n%10;
	rest=n/10;
	if(d<=5)
		n=rest*10;
	else
		n=(rest*10)+10;
	cout<<n;
	return 0;
} 