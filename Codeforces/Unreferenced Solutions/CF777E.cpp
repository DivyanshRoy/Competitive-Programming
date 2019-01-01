#include<bits/stdc++.h>
using namespace std;

bool cmp( pair< pair<long int,long int> , long int> p1,pair< pair<long int,long int> , long int> p2)
{
    if(p1.first.second<=p2.first.second)
        return p1.first.second<p2.first.first;
    return p1.first.second>p2.first.second;
}

int main()
{
    long int n,i,a,b,h;
    vector< pair< pair<long int,long int> ,long int > > vec; // a , b , h
    cin>>n;
    for(i=0;i<n;i++)
    {
        scanf("%ld %ld %ld",&a,&b,&h);
        vec.push_back(make_pair(make_pair(a,b),h));
    }
    sort(vec.begin(),vec.end(),cmp);
    vector< pair< pair<long int,long int> , long int> >::iterator iter,iter1;
    long long int th=0;
    iter1=vec.begin();
    iter1++;
    for(iter=vec.begin();iter!=vec.end();iter++)
        cout<<(iter->first).first<<" "<<(iter->first).second<<" "<<iter->second<<endl;
    return 0;
}
