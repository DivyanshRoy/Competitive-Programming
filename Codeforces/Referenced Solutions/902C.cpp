// Problem Link: https://codeforces.com/contest/902/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int h,arr[MAX],i,ans[MAX],sum=0,level_parent,left,level_first[MAX],levelfromindex[MAX];
	bool nope=1;
	
	cin>>h;
	for(i=1;i<=h+1;i++)
	{
		cin>>arr[i];
		sum+=arr[i];
		level_first[i]=100000000000000;
	}		
	for(i=2;i<=h+1;i++)
	{
		if((arr[i-1]>1)&&(arr[i]>1))
			nope=0;
	}
	
	level_parent=0;
	left=arr[1];
	level_first[0]=0;
	
	
	for(i=1;i<=sum;i++)
	{
		//cout<<i<<" "<<level_parent<<" "<<level_first[level_parent]<<endl;
		level_first[level_parent+1]=min(level_first[level_parent+1],i);
		ans[i]=level_first[level_parent];
		levelfromindex[i]=level_parent+1;
		left--;
		//cout<<left<<" "<<endl;
		if(left==0)
		{
			level_parent++;
			left=arr[level_parent+1];
		}
		//cout<<ans[i]<<" ";
	}
    //cout<<endl;
	
	if(nope)
	{
		cout<<"perfect\n";
		return 0;
	}
	else
	{
		cout<<"ambiguous\n";
		for(i=1;i<=sum;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		
		bool task=1;
		for(i=1;i<=h&&task;i++)
		{
			if((arr[i]>1)&&(arr[i+1]>1))
			{
				ans[level_first[i+1]+1]=level_first[i]+1;
				task=0;
			}
		}
		
		for(i=1;i<=sum;i++)
			cout<<ans[i]<<" ";
		cout<<endl;
		
		return 0;
	}

	return 0;
}   