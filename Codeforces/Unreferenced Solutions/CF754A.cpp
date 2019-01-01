#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,div;
    long int sum=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
        sum+=arr[i];
    }
    div=n;
    while(sum==0&&div>=0)
    {
        sum-=arr[--div];
    }
    if(div<0)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    if(div!=n)
    {
        cout<<2<<endl;
        cout<<1<<" "<<div<<endl;
        cout<<div+1<<" "<<n<<endl;
    }
    else
    {
        cout<<1<<endl;
        cout<<1<<" "<<n;
    }
    return 0;
}
