// Problem Link: https://www.codechef.com/SEPT17/problems/MINPERM

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n,arr[100005],i,ind;
	cin>>t;
	while(t--)
	{
	    cin>>n;
	    for(i=1;i<=n;i++)
	        arr[i]=i;
	    for(i=1;i<=(n/2)*2;i+=2)
	    {
	        swap(arr[i],arr[i+1]);
	    }
	    if(n%2)
	    {
	        swap(arr[n],arr[n-1]);
	    }
	    for(i=1;i<=n;i++)
	        cout<<arr[i]<<" ";
	   cout<<endl;
	}
	return 0;
}