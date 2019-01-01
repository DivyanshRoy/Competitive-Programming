#include<bits/stdc++.h>
using namespace std;

bool b[100001]={0};

void sieve()
{
    long int i,j;
    for(i=2;i<=100000;i++)
    {
        if(b[i])
            continue;
        for(j=i+i;j<=100000;j+=i)
            b[j]=1;
    }
}

bool ch(long int n)
{
    if(n>100000)
    {
        long int i,sq=sqrt(n);
        for(i=2;i<=sq;i++)
        {
            if(b[i])
                continue;
            if(n%i==0)
                return 0;
        }
        return 1;
    }
    else
        return !b[n];
}

int main()
{
    memset(b,0,100001);
    sieve();
    long int n,i,num;
    cin>>n;
    for(i=1;i<=1000;i++)
    {
        num=(n*i)+1;
        if(num<=100001)
        {
            if(b[num])
            {
                cout<<i;
                return 0;
            }
        }
        else if(ch[num])
        {
            cout<<i;
            return 0;
        }
    }
    return 0;
}
