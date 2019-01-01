#include<bits/stdc++.h>
using namespace std;

long long int n,k,arr[100005],fact[11],arrf[100005][11],cnt[11],al,f[11];
bool is[100005];

void sieve()
{
    long long int n=100005,i,j;
    for(i=0;i<n;i++)
        is[i]=0;
    for(i=2;i<n;i++)
    {
        if(is[i])
            continue;
        for(j=i+i;j<n;j+=i)
            is[j]=0;
    }
}

void func()
{
    long long int i,cn,num,sq=sqrt(k);
    al=0;
    for(i=2;i<=sqrt(k);i++)
    {
        if(is[i])
            continue;
        cn=0;
        while(k%i==0)
        {
            cn++;
            k/=i;
        }
        if(cnt>0)
        {
            al++;
            fact[al]=i;
            cnt[al]=cn;
        }
    }
    if(k!=1)
    {
        al++;
        fact[al]=k;
        cnt[al]=1;
    }
}

int main()
{
    sieve();
    cin>>n>>k;
    func();
    long long int i,cn,j,num;
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&arr[i]);
        for(j=1;j<=al;j++)
        {
            cn=0;
            num=arr[i];
            while(num%fact[j]==0)
            {
                cn++;
                num/=fact[j];
            }
            arrf[i][j]=cn;
        }
    }
    long long int l,r,ans=0;
    l=1;
    r=1;
    for(i=1;i<=al;i++)
        f[i]+=arrf[1][i];
    for(l=1;l<=n&&r<=n;l++)
    {
        while(1)
        {
            long long int tmp=0;
            if(r>=l)
            {
                tmp=0;
                for(i=1;i<=al;i++)
                {
                    if(f[i]>=cnt[i])
                        tmp++;
                }
                if(tmp==al)
                   break;
            }
            if(l==n&&r==n)
            {
                tmp=0;
                for(i=1;i<=al;i++)
                {
                    if(f[i]>=cnt[i])
                        tmp++;
                }
                if(tmp==al)
                {
                    ans++;
                }
            }
            r++;
            if(r==n+1)
                break;
            for(i=1;i<=al;i++)
                f[i]+=arrf[r][i];
            tmp=0;
            for(i=1;i<=al;i++)
            {
                if(f[i]>=cnt[i])
                    tmp++;
            }
            if(tmp==al)
                break;
        }
        ans+=(n-r+1);
        for(i=1;i<=al;i++)
            f[i]-=arrf[l][i];
    }
    cout<<ans;
    return 0;
}
