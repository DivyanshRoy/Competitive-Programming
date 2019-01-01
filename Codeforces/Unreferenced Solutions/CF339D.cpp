#include<bits/stdc++.h>
using namespace std;

long int arr[131072];

map< pair<long int,long int> , long int> m;
long int answer;

void build(long int len,long int block_size,bool b)
{
    if(block_size>len)
        return;
    long int i,half=block_size>>1;
    half--;
    if(b)   // OR
    {
        if(!half)
        {
            for(i=1;i<=len;i+=block_size)
            {
                m[make_pair(i,i+1)]=arr[i-1]|arr[i];
            }
        }
        else
        {
            for(i=1;i<=len;i+=block_size)
            {
                m[make_pair(i,i+block_size-1)]=m[make_pair(i,i+half)]|m[make_pair(i+half+1,i+block_size-1)];
            }
        }
    }
    else   // XOE
    {
        for(i=1;i<=len;i+=block_size)
        {
            m[make_pair(i,i+block_size-1)]=m[make_pair(i,i+half)]^m[make_pair(i+half+1,i+block_size-1)];
        }
    }
    build(len,block_size<<1,!b);
}

void update(long int l,long int r,long int len,long int block_size,bool b)
{
    if(block_size>len)
        return;
    long int i,half=block_size>>1;
    half--;

    if(b) // OR
    {
        m[make_pair(l,r)]=m[make_pair(l,l+half)]|m[make_pair(l+half+1,r)];
    }
    else // XOR
    {
        m[make_pair(l,r)]=m[make_pair(l,l+half)]^m[make_pair(l+half+1,r)];
    }
    update(l,r+block_size-1,len,block_size<<1,!b);
}


int main()
{
    long int l,r,n,M,i,siz=1,p,b;
    cin>>n>>M;
    for(i=0;i<n;i++)
        siz<<=1;
    for(i=0;i<siz;i++)
        scanf("%ld",&arr[i]);
    build(siz,2,1);
    while(M--)
    {
        scanf("%ld %ld",&p,&b);
        if(arr[p-1]!=b)
        {
            arr[p-1]=b;
            l=(((p-1)>>2)<<2)+1;
            r=l+3;
            if(p%2)
            {
                m[make_pair(p,p+1)]=arr[p-1]|arr[p];
            }
            else
            {
                m[make_pair(p-1,p)]=arr[p-2]|arr[p-1];
            }
            update(l,r,siz,4,0);
        }
        cout<<m[make_pair(1,siz)]<<endl;
    }
    return 0;
}
