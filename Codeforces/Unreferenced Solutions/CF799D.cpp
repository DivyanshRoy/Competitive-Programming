#include<bits/stdc++.h>
using namespace std;
const long int inf=1e9;


int main()
{
    long long int a,b,h,w,n,arr[100005],i,mn=inf,x,y;
    cin>>a>>b>>h>>w>>n;
    for(i=0;i<n;i++)
        scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    reverse(arr,arr+n);
    set< pair<long long int,long long int> > se[60];
    set< pair<long long int,long long int> >::iterator iter;
    se[0].insert(make_pair(h,w));
    for(i=0;i<n;i++)
    {
        for(iter=se[i].begin();iter!=se[i].end();iter++)
        {
            x=iter->first;
            y=iter->second;
            if(x>=a&&y>=b)
            {
                cout<<i;
                return 0;
            }
            if(x>=b&&y>=a)
            {
                cout<<i;
                return 0;
            }
            if(y<100005)
                se[i+1].insert(make_pair(x,y*arr[i]));
            if(x<100005)
            se[i+1].insert(make_pair(x*arr[i],y));
        }
    }
    for(iter=se[i].begin();iter!=se[i].end();iter++)
    {
        x=iter->first;
        y=iter->second;
        if(x>=a&&y>=b)
        {
            cout<<i;
            return 0;
        }
        if(x>=b&&y>=a)
        {
            cout<<i;
            return 0;
        }
    }
    cout<<-1;
    return 0;
}
