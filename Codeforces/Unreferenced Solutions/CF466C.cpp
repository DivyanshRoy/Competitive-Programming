#include<bits/stdc++.h>
using namespace std;


int main()
{
    long int n,i;
    cin>>n;
    long int arr[n];
    long long int sum[n];
    cin>>arr[0];
    sum[0]=arr[0];
    for(i=1;i<n;i++)
    {
        scanf("%ld",&arr[i]);
        sum[i]=sum[i-1]+arr[i];
    }
    if(sum[n-1]%3)
    {
        cout<<0;
        return 0;
    }

	return 0;
}
