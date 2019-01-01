// Problem Link: https://codeforces.com/contest/908/problem/A

#include<bits/stdc++.h>
using namespace std;

  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	char arr[100];
	int len,i,ans=0;
	
	cin>>arr;
	
	len=strlen(arr);
	
	for(i=0;i<len;i++)
	{
		if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u'||arr[i]=='1'||arr[i]=='3'||arr[i]=='5'||arr[i]=='7'||arr[i]=='9')
			ans++;
	}
	cout<<ans;
	return 0;
}