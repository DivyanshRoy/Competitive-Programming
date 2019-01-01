#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int cnt,i,n,r,avg,a,b,need,tot=0;
    cin>>n>>r>>avg;
    set<long int> s;
    map<long int, vector<long int> > m;
    for(i=0;i<n;i++)
    {
        scanf("%lld %lld",&a,&b);
        tot+=a;
        s.insert(b);
        m[b].push_back(a);
    }
    need=(n*avg)-tot;
    if(need<=0)
    {
        cout<<0;
        return 0;
    }
    cnt=0;
    set<long int>::iterator iter;
    vector<long int>::iterator iter1;
    for(iter=s.begin();iter!=s.end()&&need;iter++)
    {
        sort(m[*iter].begin(),m[*iter].end());
        for(iter1=m[*iter].begin();iter1!=m[*iter].end()&&need;iter1++)
        {
            if(*iter1<r)
            {
                if((r-*iter1)<=need)
                {
                    cnt+=(r-*iter1)*(*iter);
                    need-=(r-*iter1);
                }
                else
                {
                    cnt+=(need)*(*iter);
                    need=0;
                    break;
                }
            }
        }
    }
    cout<<cnt;
    return 0;
}
