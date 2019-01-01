// Problem Link: https://www.codechef.com/COOK82/problems/COOK82A

#include<bits/stdc++.h>
using namespace std;

int main()
{
    string bar="Barcelona",rm="RealMadrid",mal="Malaga",eib="Eibar",str;
    int t,b,r,m,e,n;
    cin>>t;
    while(t--)
    {
        cin>>str>>n;
        if(str==bar)
            b=n;
        else if(str==rm)
            r=n;
        else if(str==mal)
            m=n;
        else if(str==eib)
            e=n;
        cin>>str>>n;
        if(str==bar)
            b=n;
        else if(str==rm)
            r=n;
        else if(str==mal)
            m=n;
        else if(str==eib)
            e=n;
        cin>>str>>n;
        if(str==bar)
            b=n;
        else if(str==rm)
            r=n;
        else if(str==mal)
            m=n;
        else if(str==eib)
            e=n;
        cin>>str>>n;
        if(str==bar)
            b=n;
        else if(str==rm)
            r=n;
        else if(str==mal)
            m=n;
        else if(str==eib)
            e=n;
        if(r<m&&b>e)
            cout<<"Barcelona\n";
        else
            cout<<"RealMadrid\n";
    }
    return 0;
}
