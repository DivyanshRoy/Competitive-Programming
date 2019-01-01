// Problem Link: https://www.spoj.com/problems/MATSUM/

#include <bits/stdc++.h>
using namespace std;
 
long long int n,table[1030][1030],varr[1030][1030];
 
void update(int x,int y,long long int val)
{
    int i=x,j=y;
    for(;i<=n;i+=(i&-i))
    {
        for(j=y;j<=n;j+=(j&-j))
        {
            table[i][j]+=val;
        }
    }
}
 
long long int ret(int x,int y)
{
    long long int sum=0;
    int i=x,j=y;
    for(;i>0;i-=(i&-i))
    {
        for(j=y;j>0;j-=(j&-j))
        {
            sum+=table[i][j];
        }
    }
    return sum;
}
 
int main()
{
    int t,i,j,a,b,c,d;
    long long int v;
    char arr[20];
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        n++;
        for(i=0;i<=n;i++)
        {
            for(j=0;j<=n;j++)
            {
            	table[i][j]=0;
            	varr[i][j]=0;
            }
        }
        while(1)
        {
            scanf("%s",arr);
            if(arr[0]=='S')
            {
                if(arr[1]=='E')
                {
                    scanf("%lld %lld %lld",&a,&b,&c);
                    a++;
                    b++;
                    update(a,b,c-varr[a][b]);
                    varr[a][b]=c;
                }
                else
                {
                    scanf("%lld %lld %lld %lld",&a,&b,&c,&d);
                    a++;
                    b++;
                    c++;
                    d++;
                    v=ret(c,d)+ret(a-1,b-1)-ret(a-1,d)-ret(c,b-1);
                    printf("%lld\n",v);
                }
            }
            else
                break;
        }
    }
    return 0;
}