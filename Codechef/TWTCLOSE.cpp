// Problem Link: https://www.codechef.com/problems/TWTCLOSE

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,k,i,ans=0,a;
    bool b[1001];
    cin>>n>>k;
    for(i=1;i<=n;i++)
        b[i]=0;
    string str;
    while(k--)
    {
        cin>>str;
        if(str=="CLICK")
        {
            cin>>a;
            if(b[a])
                ans--;
            else
                ans++;
            b[a]=!(b[a]);
        }
        else
        {
            ans=0;
            for(i=1;i<=n;i++)
                b[i]=0;
        }
        cout<<ans<<endl;
    }
    return 0;
}
