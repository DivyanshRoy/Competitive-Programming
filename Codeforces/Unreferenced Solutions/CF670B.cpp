#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,k,i;
    cin>>n>>k;
    long int id[n];
    long long int val[n];
    for(i=0;i<n;i++)
        scanf("%ld",&id[i]);
    val[0]=1;
    for(i=1;i<n;i++)
    {
        val[i]=val[i-1]+i+1;
    }
    for(i=0;i<n;i++)
    {
        //cout<<"..."<<id[i]<<endl;
        if(val[i]>=k)
        {
            if(i>0)
            k-=val[i-1];
            cout<<id[k-1];
            break;
        }
    }
    return 0;
}
