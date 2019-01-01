#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    long int a,b;
    cin>>n;
    set<long int> s;
    map<long int, set<long int> > m;
    while(n--)
    {
        cin>>a>>b;
        s.insert(a);
        m[a].insert(b);
    }
    bool bo;
    set<long int>::iterator iter,iiter;
    long int pre=0;
    for(iter=s.begin();iter!=s.end();iter++)
    {
        bo=0;
        for(iiter=m[*iter].begin();iiter!=m[*iter].end();iiter++)
        {
            if(*iiter>=pre)
            {
                pre=*iiter;
            }
            else
            {
                bo=1;
                break;
            }
        }
        if(*iter>=pre&&bo)
        {
            pre=*iter;
        }
    }
    cout<<pre;
    return 0;
}
