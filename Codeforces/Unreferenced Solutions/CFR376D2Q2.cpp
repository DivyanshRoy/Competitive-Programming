#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,i;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    for(i=0;i<n;i++)
    {
        if(arr[i]%2==0)
            continue;
        else
        {
            if(i==n-1)
            {
                cout<<"NO";
                return 0;
            }
            if(arr[i+1]==0)
            {
                cout<<"NO";
                return 0;
            }
            arr[i+1]--;
        }
    }
    cout<<"YES";
    return 0;
}
