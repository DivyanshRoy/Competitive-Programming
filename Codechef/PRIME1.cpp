// Problem Link: https://www.codechef.com/problems/PRIME1

#include<bits/stdc++.h>
using namespace std;

bool is[100005];

void sieve()
{
    long int i,j,mx=100000;
    for(i = 0;i<=mx;i++)
        is[i]=1;
    for(i=2;i<=mx;i++)
    {
        if(is[i])
        {
            for(j = i+i;j<=mx;j+=i)
                is[j]=0;
        }
    }
}

void segmented_sieve(long long int a,long long int b)
{
    bool pp[b-a+1];
    memset(pp,1,sizeof(pp));
    long long int i,j,num;
    for(i=2;i*i<=b;i++)
    {
        if(!is[i])
            continue;
        num=(a/i)*i;
        if(num<a)
            num+=i;
        for(j=num;j<=b;j+=i)
        {
            if(j==i)
                continue;
            pp[j-a]=0;
        }
    }
    for(i=max(a,2LL);i<=b;i++)
    {
        if(pp[i-a])
            cout<<i<<endl;
    }
    cout<<endl;
}

int main()
{
    sieve();
    long long int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>m>>n;
        segmented_sieve(m,n);
    }
    return 0;
}
