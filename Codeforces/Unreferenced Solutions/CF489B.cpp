#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,m,i,j,cnt=0;
    cin>>n;
    int b[n];
    for(i=0;i<n;i++)
        cin>>b[i];
    cin>>m;
    int g[m];
    bool a[m]={0};
    for(i=0;i<m;i++)
        cin>>g[i];
    sort(b,b+n);
    sort(g,g+m);
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(a[j])
                continue;
            if((b[i]-g[j]==1)||(g[j]-b[i]==1)||g[j]==b[i])
            {
                cnt++;
                a[j]=1;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}
