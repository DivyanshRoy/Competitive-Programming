#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t,i,n,k;
    cin>>n>>k;
    t=240-k;
    for(i=1;i<=n;i++)
    {
        if(t<5*i)
            break;
        t-=5*i;
    }
    cout<<i-1;
	return 0;
}
