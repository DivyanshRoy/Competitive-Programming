#include<bits/stdc++.h>
using namespace std;

long int arr[100001][2];
map<long int,long int> pre,next;
void recur(long int cur)
{
    while(arr[next[cur]][1]!=0)
    {
        cout<<arr[next[cur]][1]<<" ";
        cur=next[cur];
    }
}

int main()
{
    long int n,i,u,v;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>u>>v;
        arr[i][0]=u;
        arr[i][1]=v;
        pre[u]=i;
        next[v]=i;
    }
    long int cur;
    cur=pre[0];
    cout<<cur<<" ";
    cur=pre[arr[cur+2][1]];
    cout<<arr[cur][1]<<" ";
    //recur(next[cur]);
    return 0;
}
