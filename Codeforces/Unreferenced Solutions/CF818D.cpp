#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,a,c[100005],i,cnt[1000005],mn=1000000008;
    set<long int> se;
    cin>>n>>a;
    for(i=1;i<=1000000;i++)
        cnt[i]=0;
    for(i=1;i<=n;i++)
    {
        cin>>c[i];
        if(c[i]==a)
            mn=min(mn,i-1);
    }

    if(mn==1000000008)
    {
        cout<<c[1];
        return 0;
    }
    for(i=1;i<=mn;i++)
    {
        se.insert(c[i]);
        cnt[c[i]]++;
    }

    set<long int>::iterator iter,iter2;
    for(i=mn+1;i<=n;i++)
    {
        if(se.empty())
        {
            cout<<-1;
            return 0;
        }
        cnt[c[i]]++;
        if(c[i]==a)
        {
            for(iter=se.begin();iter!=se.end();)
            {
                if(cnt[*iter]<cnt[a])
                {
                    iter2=iter;
                    iter2++;
                    se.erase(iter);
                    iter=iter2;
                }
                else
                    iter++;
            }
        }
    }

    if(se.empty())
    {
        cout<<-1;
        return 0;
    }
    iter=se.begin();
    cout<<*iter;

    return 0;
}
