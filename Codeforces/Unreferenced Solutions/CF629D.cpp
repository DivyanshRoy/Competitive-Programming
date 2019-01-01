#include<bits/stdc++.h>
using namespace std;

#define PI 3.141592653589793238462643383279502

int main()
{
    long int n,i,j;
    cin>>n;
    int arr[n][2],cnt[n]={0};
    for(i=0;i<n;i++)
        scanf("%d %d",&arr[i][0],&arr[i][1]);
    for(i=n-1;i>=0;i--)
    {
        for(j=i-1;j>=0;j--)
            if((long int)arr[j][0]*(long int)arr[j][0]*(long int)arr[j][1]<(long int)arr[i][0]*(long int)arr[i][0]*(long int)arr[i][1])
                cnt[i]++;
    }
    int mx=0,loc=0;
    for(i=0;i<n;i++)
        if(cnt[i]>mx)
        {
        mx=cnt[i];
        loc=i;
        }
    long double val=(PI*(long double)(arr[loc][0])*(long double)(arr[loc][0])*(long double)(arr[loc][1]));
    for(i=loc-1;i>=0;i--)
    {
        if((long int)arr[i][0]*(long int)arr[i][0]*(long int)arr[i][1]<(long int)arr[loc][0]*(long int)arr[loc][0]*(long int)arr[loc][1])
            val+=(PI*(long double)(arr[i][0])*(long double)(arr[i][0])*(long double)(arr[i][1]));
    }
    cout<<val;
    return 0;
}
