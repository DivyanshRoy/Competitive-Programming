#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i;
    bool b=1;
    string str;
    set<string> p,e,c;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
        cin>>str;
        p.insert(str);
        c.insert(str);
    }
    for(i=0;i<m;i++)
    {
        cin>>str;
        e.insert(str);
        c.insert(str);
    }
    long int ps,cs,es;
    ps=p.size();
    cs=c.size();
    es=e.size();
    cs=ps+es-cs;
    if(ps-cs>es-cs)
    {
        {
            cout<<"YES";
            return 0;
        }
    }
    else if(es-cs>ps-cs)
    {
        {
            cout<<"NO";
            return 0;
        }
    }
    else
    {
        if(cs%2==0)
        {
            cout<<"NO";
            return 0;
        }
        else
        {
            cout<<"YES";
            return 0;
        }
    }

    set<string>::iterator iter;
    while(1)
    {
        if(b)
        {
            if(p.empty())
            {
                cout<<"NO";
                return 0;
            }
            iter=p.begin();
            p.erase(*iter);
            e.erase(*iter);
        }
        else
        {
            if(e.empty())
            {
                cout<<"YES";
                return 0;
            }
            iter=e.begin();
            p.erase(*iter);
            e.erase(*iter);
        }
        b=!b;
    }
    return 0;
}
