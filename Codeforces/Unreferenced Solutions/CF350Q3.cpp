#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int e,n,m,i;
    cin>>n;
    map<long int,long int> ma;
    set<long int> s;
    for(i=0;i<n;i++)
    {
        cin>>e;
        if(s.size()!=0){
        if(s.find(e)==s.end())
        {
            ma.insert(std::pair<long int,long int>(e,1));
            s.insert(e);
        }
        else
            ma[e]++;
        }
        else
        {
            ma.insert(std::pair<long int,long int>(e,1));
            s.insert(e);
        }
    }
    long int mx=0,in=-1,a[n],b[n];
    cin>>m;
    for(i=0;i<m;i++)
    {
        scanf("%ld %ld",&a[i],&b[i]);
        e=a[i];
        if(s.find(a[i])!=s.end())
        {
            if(mx<ma[e])
            {
                mx=ma[e];
                in=i+1;
            }
        }
    }
    cout<<in;
    return 0;
}
