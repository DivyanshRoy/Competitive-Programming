#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,i;
    cin>>n;
    long int val,na=1,arr[n];
    vector< pair<long int,long int> > vec;
    for(i=0;i<n;i++)
    {
        scanf("%ld",&val);
        vec.push_back(make_pair(val,i));
    }
    sort(vec.begin(),vec.end());
    vector< pair<long int,long int> >::iterator iter;
    for(iter=vec.begin();iter!=vec.end();iter++)
    {
        if(iter->first<na)
        {
            arr[iter->second]=na++;
        }
        else
        {
            arr[iter->second]=iter->first;
            na=iter->first;
            na++;
        }
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}
