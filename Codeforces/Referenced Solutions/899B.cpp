// Problem Link: https://codeforces.com/contest/899/problem/B

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	int month,i,n,arr[30],j,leap=0;
	bool yes=0;
	map<int,int> mp;
	mp[0]=31;
	mp[1]=28;
	mp[1]=29;
	mp[2]=31;
	mp[3]=30;
	mp[4]=31;
	mp[5]=30;
	mp[6]=31;
	mp[7]=31;
	mp[8]=30;
	mp[9]=31;
	mp[10]=30;
	mp[11]=31;
	
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>arr[i];
		
	for(i=0;i<12;i++)
	{
		leap=0;
		for(j=1;j<=n;j++)
		{
			if(arr[j]==29&&(i+j-1)%12==1)
				leap++;
			else if(arr[j]==28&&(i+j-1)%12==1)
			{
			}
			else if(mp[(i+j-1)%12]!=arr[j])
				break;
			
		}
		if(j==n+1&&leap<2)
			yes=1;
	}
	
	if(yes)
		cout<<"YES";
	else
		cout<<"NO";
	return 0;
}   