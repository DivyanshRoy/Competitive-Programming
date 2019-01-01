#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,i,cnt=0;
    long int arr[10001];
    cin>>n;
    set<long int> s;
    for(i=1;i<=n;i++)
        scanf("%ld",&arr[i]);
    for(i=1;i<=n;i++)
    {
        if(arr[i]==i)
            cnt++;
        else
            s.insert(arr[i]);
    }
    cout<<cnt+s.size()/2;
    return 0;
}
