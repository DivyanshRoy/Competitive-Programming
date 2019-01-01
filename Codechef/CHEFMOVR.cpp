// Problem Link: https://www.codechef.com/AUG17/problems/CHEFMOVR

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,n,d,i,arr[100005],sum,cnt,df;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld %lld",&n,&d);
        sum=cnt=0;
        for(i=1;i<=n;i++)
        {
            scanf("%lld",&arr[i]);
            sum+=arr[i];
        }
        if(sum%n!=0)
        {
            cout<<"-1\n";
            continue;
        }
        else
        {
            for(i=1;i<=n-d;i++)
            {
                
                df=(sum/n)-arr[i];
                if(df<0)
                    cnt-=df;
                else
                    cnt+=df;
                arr[i]+=df;
                arr[i+d]-=df;
            }
        }
        bool f=0;
        for(i=1;i<=n;i++)
        {
            if(arr[i]!=(sum/n))
            {
                f=1;
                break;
            }
        }
        if(f)
            cout<<"-1\n";
        else
            cout<<cnt<<endl;
    }
    return 0;
}
