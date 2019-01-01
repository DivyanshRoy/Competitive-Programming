// Problem Link: https://www.codechef.com/JUNE17/problems/GOODSET

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

int main()
{
    int t,n,i;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(i=1;i<=n;i++)
        {
            cout<<(2*i)-1<<" ";
        }
        cout<<endl;
    }
    return 0;
}
