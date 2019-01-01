// Problem Link: https://www.codechef.com/MAY17/problems/CHEFSUBA

#include<bits/stdc++.h>
using namespace std;
#define sz 100005
 
//Sliding Window Code:- GeeksForGeeks
 
int main()
{
    long int n,i,arr[300005],l,r,k,p,cnt=0,ta[300005],ans[300005],aa=0,tl=0,mx=0,div=0,tot=0;
    cin>>n>>k>>p;
    if(k>n){
    k=n;
    }
   // assert(n>=k);
    
    for(i=0;i<n;i++)
    {
        scanf("%ld",&arr[i]);
        if(arr[i])
            tot++;
    }
    
    
    for(i=0;i<k;i++)
    {
        if(arr[i])
            cnt++;
    }
    ta[tl++]=cnt;
    mx=max(mx,cnt);
    l=1,r=l+k-1;
    for(;l<n;l++)
    {
        if(arr[l-1])
            cnt--;
        if(arr[r])
            cnt++;
        r=(r+1)%n;
        ta[tl++]=cnt;
        mx=max(mx,cnt);
    }
    for(i=0;i<n-k+1;i++)
    {
        ta[tl++]=ta[i];
    }
    
    if(div>0)
    {
        long int mxv=0,j,li=n,ri=n+k;
        for(i=0;i<n;i++)
        {
            mxv=0;
            for(j=li;j<ri;j++)
                mxv=max(mxv,ta[j]);
            li++;
            ri++;
            ans[aa++]=mxv;
        }
    }
    else
    {
    long int li,ri;
    li=0;
    ri=tl-1;
    for(;li<=ri;li++,ri--)
        swap(ta[li],ta[ri]);
 
    std::deque<long int>  Qi(300005);
    for (i = 0; i < n-k+1; ++i)
    {
        while ( (!Qi.empty()) && ta[i] >= ta[Qi.back()])
        Qi.pop_back();
        Qi.push_back(i);
    }
 
    for ( ; i < n+n-k+1; ++i)
    {
        ans[aa++]=ta[Qi.front()];
 
        while ( (!Qi.empty()) && Qi.front() <= i - n+k-1)
            Qi.pop_front();
        while ( (!Qi.empty()) && ta[i] >= ta[Qi.back()])
            Qi.pop_back();
        Qi.push_back(i);
    }
    ans[aa++]=ta[Qi.front()];
    
    }
 
    char str[100005];
    cin>>str;
    aa=0;
    for(i=0;i<p;i++)
    {
        if(str[i]=='?')
        {
            if(div>0)
            {
                printf("%ld\n",(tot*div)+ans[aa]);
            }
            else
                printf("%ld\n",ans[aa]);
        }
        else
        {
            aa=(aa+1)%n;
        }
    }
    return 0;
}