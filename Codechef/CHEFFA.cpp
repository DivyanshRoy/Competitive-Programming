// Problem Link: https://www.codechef.com/AUG17/problems/CHEFFA

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int ans=0,ol;
vector<long long int> vec;

unordered_map< long long int ,long long int> ma[100];

void init()
{
    long long int i,len=vec.size();
    i=1;
    ma[i][vec[i-1]*283+vec[i]]=(long long int)1;
}

void rec()
{
    if(ol<2)
        return;
    long long int i,len=vec.size();
    for(i=1;i<len;i++)
    {
        unordered_map< long long int , long long int>::iterator iter1,iter2;
        long long int iter;
        for(iter1=ma[i].begin();iter1!=ma[i].end();iter1++)
        {
            iter=iter1->first;
            if(i>=ol-1)
            {
                ans=(ans+ma[i][iter1->first])%mod;
            }
            if(i==len-1)
            {
                len++;
                vec.push_back(0);
            }
            long long int fir,sec,mn,j;
            long long int p;
            mn=min(iter/283,iter%283);
            if(i<ol-1)
                j=0;
            else
                j=1;
            for(;j<=mn;j++)
            {
                fir=iter%283-j;
                sec=j+vec[i+1];
                p=fir*283+sec;
                iter2=ma[i+1].find(p);
                if(iter2==ma[i+1].end())
                {
                    ma[i+1][p]=ma[i][iter];
                }
                else
                {
                    iter2->second=(iter2->second+iter1->second)%mod;
                }
            }
        }
    }
}

int main()
{
    long long int i,n,v,t;
    cin>>t;
    while(t--)
    {
        ans=0;
        vec.clear();
        for(i=0;i<100;i++)
            ma[i].clear();
        scanf("%lld",&n);
        if(n==1)
        {
            cout<<1<<endl;
            continue;
        }
        ol=n;
        for(i=0;i<n;i++)
        {
            scanf("%lld",&v);
            vec.push_back(v);
        }
        init();
        rec();
        cout<<ans<<endl;
    }
    return 0;
}
