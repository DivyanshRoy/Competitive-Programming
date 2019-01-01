#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,m,i,val;
    cin>>n>>m;
    map<long int, bool> arr;
    for(i=0;i<n;i++)
    {
        cin>>val;
        arr[val]=1;
    }
    vector<long int> s;
    for(i=1;i<=1000000000&&m>=i;i++)
    {
        if(arr[i])
            continue;
        else
        {
            s.push_back(i);
            m-=i;
        }
    }
    cout<<s.size()<<endl;
    vector<long int>::iterator iter;
    for(iter=s.begin();iter!=s.end();iter++)
        cout<<*iter<<" ";
    return 0;
}
