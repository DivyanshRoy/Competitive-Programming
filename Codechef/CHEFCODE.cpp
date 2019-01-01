// Problem Link: https://www.codechef.com/MAY17/problems/CHEFCODE

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int v,n,k,arr[30],i,ans=0;
    cin>>n>>k;
    for(i=0;i<n;i++)
        cin>>arr[i];
    sort(arr,arr+n);
    set<long long int> se;
    set< pair<long long int,long long int> > tmp,st;
    set<long long int>::iterator iter;
    set< pair<long long int,long long int> >::iterator titer;
    map<long long int,long long int> ma;
    for(i=0;i<n;i++)
    {
        if(arr[i]>k)
            break;
        for(iter=se.begin();iter!=se.end();iter++)
        {
            if(((long double)(*iter)*(long double)arr[i])>(long double)k)
                break;
            v=(*iter)*arr[i];
            if(se.find(v)==se.end())
            {
                tmp.insert(make_pair(v,ma[*iter]));
            }
            else
            {
                st.insert(make_pair(v,ma[*iter]));
                ans+=ma[*iter];
            }
        }
        for(titer=st.begin();titer!=st.end();titer++)
        {
            ma[titer->first]+=titer->second;
        }
        st.clear();
        for(titer=tmp.begin();titer!=tmp.end();titer++)
        {
            se.insert(titer->first);
            ma[titer->first]=titer->second;
            ans+=titer->second;
        }
        tmp.clear();
        if(se.find(arr[i])==se.end())
        {
            se.insert(arr[i]);
            ma[arr[i]]=1;
            ans++;
        }
        else
        {
            ma[arr[i]]++;
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
