// Problem Link: https://www.codechef.com/APRIL17/problems/SIMDISH

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,i,cnt;
    set<string> m1;
    cin>>t;
    string str;
    while(t--)
    {
        m1.clear();
        cnt=0;
        for(i=0;i<4;i++)
        {
            cin>>str;
            m1.insert(str);
        }
        for(i=0;i<4;i++)
        {
            cin>>str;
            if(m1.find(str)!=m1.end())
                cnt++;
        }
        if(cnt>1)
            cout<<"similar\n";
        else
            cout<<"dissimilar\n";
    }
    return 0;
}
