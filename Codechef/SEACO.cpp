// Problem Link: https://www.codechef.com/SEPT17/problems/SEACO

#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long int t,n,m,i,a[100005],b[100005],c[100005];
    
long long int bitv[100005],bita[100005];

void updatev(long long int index,long long int val)
{
    for(;index<=m;index+=index&(-index))
    {
        bitv[index]=(bitv[index]+val)%mod;
    }
}

long long int retv(long long int index)
{
    long long int sum=0;
    for(;index>0;index-=index&(-index))
    {
        sum=(sum+bitv[index]);
    }
    return sum;
}

void updatea(long long int index,long long int val)
{
    for(;index<=n;index+=index&(-index))
    {
        bita[index]=(bita[index]+val)%mod;
    }
}

long long int reta(long long int index)
{
    long long int sum=0;
    for(;index>0;index-=index&(-index))
    {
        sum=(sum+bita[index]);
    }
    return sum;
}


int main()
{
	cin>>t;
    while(t--)
    {
        scanf("%lld %lld",&n,&m);
        for(i=0;i<100005;i++)
            bita[i]=bitv[i]=0;
        updatev(1,1);
        updatev(m+1,mod-1);
        for(i=1;i<=m;i++)
        {
            scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
        }
        long long int cnt;
        for(i=m;i>=1;i--)
        {
            cnt=retv(i);
            if(a[i]==1)
            {
                updatea(b[i],cnt%mod);
                updatea(c[i]+1,mod-(cnt%mod));
            }
            else
            {
                updatev(b[i],cnt%mod);
                updatev(c[i]+1,mod-(cnt%mod));
            }
        }
        for(i=1;i<=n;i++)
        {
            cnt=reta(i);
            cout<<cnt%mod<<" ";
        }
        cout<<endl;
    }
	return 0;
}