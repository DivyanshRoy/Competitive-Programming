// Problem Link: https://www.codechef.com/SEPT17/problems/CHEFSUM

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
            cin>>arr[i];
        ind=1;
        for(i=2;i<=n;i++)
        {
            if(arr[i]<arr[ind])
                ind=i;
        }
        cout<<ind<<endl;
	}
	return 0;
}