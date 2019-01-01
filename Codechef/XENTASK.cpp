// Problem Link: https://www.codechef.com/MARCH17/problems/XENTASK

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    long int x[20005],y[20005],i,n,x0,x1,y0,y1;
    bool b;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        x0=x1=y0=y1=0;
        b=1;
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&x[i]);
            if(b)
                x0+=x[i];
            else
                x1+=x[i];
            b=!b;
        }
        b=0;
        for(i=1;i<=n;i++)
        {
            scanf("%ld",&y[i]);
            if(b)
                y0+=y[i];
            else
                y1+=y[i];
            b=!b;
        }
        n=min(x0+y0,x1+y1);
        printf("%ld\n",n);
    }
    return 0;
}
