// Problem Link: https://www.codechef.com/MARCH17/problems/SORTROW

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,i,j,a[302][302];
    vector< vector<long int> > arr;
    vector<long int> v;
    scanf("%ld",&n);
    v.resize(n+1);
    arr.push_back(v);
    for(i=1;i<=n;i++)
    {
        arr.push_back(v);
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf("%ld",&arr[i][j]);
            a[i][j]=arr[i][j];
        }
    }
    long int ran[90005],ran1[90005],cnt,cnt1,df;
    for(i=1;i<=n;i++)
    {
        sort(arr[i].begin(),arr[i].end());
        for(j=1;j<=n;j++)
        {
            ran[arr[i][j]]=j;
            ran1[arr[i][j]]=n-j+1;
        }
        cnt=cnt1=0;
        for(j=1;j<=n;j++)
        {
            df=j-ran[a[i][j]];
            if(df<0)
                df*=-1;
            cnt+=df;

            df=j-ran1[a[i][j]];
            if(df<0)
                df*=-1;
            cnt1+=df;
        }
        if(cnt1<cnt)
            reverse(arr[i].begin()+1,arr[i].end());
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}
