// Problem Link: https://www.spoj.com/problems/ABCDEF/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long int n,i,a,b,c,d,e,f,j;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    long int v1[n*n*n],v2[n*n*n],it1,it2;
    it1=it2=0;
    for(a=0;a<n;a++)
    {
        for(b=0;b<n;b++)
        {
            for(c=0;c<n;c++)
            {
                v1[it1++]=arr[a]*arr[b]+arr[c];
            }
        }
    }
 
    for(d=0;d<n;d++)
    {
        if(arr[d]==0)
            continue;
        for(e=0;e<n;e++)
        {
            for(f=0;f<n;f++)
            {
                v2[it2++]=arr[d]*(arr[e]+arr[f]);
            }
        }
    }
 
    sort(v1,v1+it1);
    sort(v2,v2+it2);
 
    long int hi1,hi2,lo1,lo2,mid1,mid2,cnt=0,mx,mn;
 
    for(i=0;i<it1;i++)
    {
        lo1=0;
        hi1=it2-1;
        while(lo1<=hi1)
        {
            mid1=(lo1+hi1)/2;
            if(v2[mid1]<v1[i])
            {
                lo1=mid1+1;
            }
            else if(v2[mid1]>v1[i])
            {
                hi1=mid1-1;
            }
            else if(v2[mid1]==v1[i])
            {
                if(v2[mid1-1]==v1[i]&&mid1>0)
                {
                    hi1=mid1-1;
                }
                else
                    break;
            }
        }
        mn=mid1;
 
        lo2=0;
        hi2=it2-1;
        while(lo2<=hi2)
        {
            mid2=(lo2+hi2)/2;
            if(v2[mid2]<v1[i])
            {
                lo2=mid2+1;
            }
            else if(v2[mid2]>v1[i])
            {
                hi2=mid2-1;
            }
            else if(v2[mid2]==v1[i])
            {
                if(v2[mid2+1]==v1[i]&&mid2<it2-1)
                {
                    lo2=mid2+1;
                }
                else
                    break;
            }
        }
        mx=mid2;
        if(lo1<=hi1&&lo2<=hi2)
        cnt+=mx-mn+1;
    }
    cout<<cnt;
    return 0;
 
}