#include<bits/stdc++.h>
using namespace std;

int main()
{
    int arr[10001],i,n,cnt=0;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%d",&arr[i]);
    for(i=1;i<=n;i++)
    {
        if(arr[i]==i)
            cnt+=2;
        else if(arr[arr[i]]==i)
            cnt++;
    }
    cout<<cnt/2;
    return 0;
}
