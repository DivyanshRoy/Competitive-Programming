#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int i,n,t,loc=-1,cnt=0;
    cin>>n>>t;
    char arr[n];
    cin>>arr;
    stack<char> s;
    for(i=0;i<t;i++)
    {
        if(arr[i]=='.')
        {
            loc=i;
            continue;
        }
        if(arr[n-i-1]>='5'&&arr[n-i-1]<='9')
        {
            arr[n-i-2]++;
            if(arr[n-i-2]=='0')
                arr[n-i-3]++;
        }
        else
        {
            cnt++;
        }

    }
    cout<<n-t+cnt<<endl;
    for(i=0;i<n-t+cnt;i++)
        cout<<arr[i];
    if(loc==n-t-1+cnt)
        cout<<"\b";
    else if(loc==n-t-2+cnt&&arr[n-t-1+cnt]=='0')
        cout<<"\b\b";

    return 0;
}
