// Problem Link: https://codeforces.com/contest/898/problem/E

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	

	long long int n,arr[MAX],i,sqsz,nsqsz,sq,ans=0;
	sqsz=nsqsz=0;
	
	multiset<long long int> sqtonsq,nsqtosq;
	multiset<long long int>::iterator iter;
	
	cin>>n;
	
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
		sq=sqrt(arr[i]);
		if(arr[i]==(sq*sq))
		{
			sqsz++;
			if(arr[i]==0)
				sqtonsq.insert(2);
			else
				sqtonsq.insert(1);
		}
		else
		{
			nsqsz++;
			long long int mn=arr[i]-(sq*sq);
			mn=min(mn,((sq+1)*(sq+1)-arr[i]));
			nsqtosq.insert(mn);
		}
	}
	
	if(sqsz!=nsqsz)
	{
		if(sqsz>nsqsz)
		{
			i=0;
			
			for(iter=sqtonsq.begin();iter!=sqtonsq.end()&&i<((n/2)-nsqsz);iter++,i++)
			{
				ans+=*iter;
			}
			
		}
		else
		{
			i=0;
			
			for(iter=nsqtosq.begin();iter!=nsqtosq.end()&&i<((n/2)-sqsz);iter++,i++)
			{
				ans+=*iter;
			}
		}
	}
	cout<<ans;
	return 0;
}   