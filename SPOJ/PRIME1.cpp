// Problem Link: https://www.spoj.com/problems/PRIME1/

#include<bits/stdc++.h>
using namespace std;
#define len 31622
 
bool arr[len+1];
 
void sieve()
{
    long long int i,j;
    for(i=2;i<=len;i++)
    {
        if(!arr[i])
        {
            for(j=i+i;j<=len;j+=i)
            {
                arr[j]=1;
            }
        }
    }
}
 
int main()
{
    sieve();
    long long int t,a,b,i,cnt,j;
    bool flag;
    cin>>t;
    while(t--)
    {
        cnt=0;
        scanf("%lld %lld",&a,&b);
        if(a<2)
            a=2;
        for(i=a;i<=b;i++)
        {
            flag=0;
            for(j=2;j<=sqrt(i);j++)
            {
                if(!arr[j])
                {
                    if(i%j==0)
                    {
                        flag=1;
                        break;
                    }
                }
            }
            if(!flag)
                cout<<i<<endl;
        }
        cout<<endl;
    }
    return 0;
}
 