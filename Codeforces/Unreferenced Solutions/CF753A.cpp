#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    vector<int> s;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        s.push_back(i);
        n-=i;
    }
    if(n)
    {
        s.back()+=n;
    }
    cout<<s.size()<<endl;
    vector<int>::iterator iter;
    for(iter=s.begin();iter!=s.end();iter++)
        cout<<*iter<<" ";
    return 0;
}
