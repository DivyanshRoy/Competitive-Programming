// Problem Link: https://www.codechef.com/OCT17/problems/CHEFCOUN

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long long int t,n,i,sum,aim=1,x;
	for(i=1;i<=32;i++)
	    aim=aim*2;
	cin>>t;
	while(t--)
	{
	    cin>>n;
        x=(aim/(n+1));
        sum=0;
        for(i=1;i<n-1;i++)
        {
            cout<<x<<" ";
            sum+=x;
        }
        if(n>1)
        {
            if((x*(n-1))%2==0)
            {
                cout<<x<<" ";
                sum+=x;
            }
            else
            {
                cout<<x+1<<" ";
                sum+=(x+1);
            }
        }
        cout<<(aim-sum)/2<<endl;
	}
	
	return 0;
}
