// Problem Link: https://www.codechef.com/JAN18/problems/RECTANGL

#include<bits/stdc++.h>
using namespace std;

  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int t,arr[5],i;
	
	cin>>t;
	
	while(t--)
	{
		for(i=0;i<4;i++)
			cin>>arr[i];
		sort(arr,arr+4);
		if(arr[0]==arr[1]&&arr[2]==arr[3])
			cout<<"YES\n";
		else
			cout<<"NO\n";
	}


	return 0;
}