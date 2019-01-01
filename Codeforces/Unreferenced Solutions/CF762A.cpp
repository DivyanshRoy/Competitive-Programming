#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k,ccnt,tcnt,i,lim;
    cin>>n>>k;
    ccnt=tcnt=0;
    lim=sqrt(n);
    vector<long int> vec;
    for(i=1;i<=lim;i++)
    {
        if(n%i==0)
        {
            ccnt++;
            tcnt++;
            if(ccnt==k)
            {
                cout<<i;
                return 0;
            }
            //vec.push_back(i);
        }
    }
    if((n%lim)==0&&lim==n/lim)
    {
        i=lim-1;
        if(tcnt*2-1<k)
        {
            cout<<"-1";
            return 0;
        }
    }
    else
    {
        i=lim;
        if(tcnt*2<k)
        {
            cout<<"-1";
            return 0;
        }
    }
    for(;i>=1;i--)
    {
        if(n%i==0)
        {
            ccnt++;
            tcnt++;
            if(ccnt==k)
            {
                cout<<n/i;
                return 0;
            }
            //vec.push_back(i);
        }
    }
    return 0;
}
