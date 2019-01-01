// Problem Link: https://codeforces.com/contest/894/problem/A

#include<bits/stdc++.h>
using namespace std;


int main()
{

	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	char arr[200];
	long long int len,i,c0,c1,c2;
	cin>>arr;
	len=strlen(arr);
	c0=c1=c2=0;
	
	for(i=0;i<len;i++)
	{
		if(arr[i]=='Q')
		{
			c0++;
			c2+=c1;
		}
		else if(arr[i]=='A')
		{
			c1+=c0;
		}
	}
	cout<<c2;
	return 0;
}