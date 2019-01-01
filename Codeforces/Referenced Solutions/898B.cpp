// Problem Link: https://codeforces.com/contest/898/problem/B

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	long long int n,a,b,x,y;
	cin>>n>>a>>b;
	x=0;
	
	while(1)
	{
		y=(n-(x*a))/b;
		if(y<0)
			break;
		if(((x*a)+(y*b))==n)
			break;
		
		x++;
	}
	if(y<0)
		cout<<"NO";
	else
	{
		cout<<"YES\n"<<x<<" "<<y;
	}
	return 0;
}   