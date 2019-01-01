// Problem Link: https://codeforces.com/contest/484/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,i,l,r,prev,j,cur;
	
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>l>>r;
		prev=l;
		for(j=0;j<=60;j++)
		{
			cur=prev|((long long int)1<<j);
			if(cur<=r)
			{
				prev=cur;
			}
			else
				break;
		}
		cout<<prev<<endl;
	}

	return 0;
}