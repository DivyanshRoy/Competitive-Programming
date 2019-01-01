#include<bits/stdc++.h>
using namespace std;

bool b[1001];

void sieve()
{
    int i,j;
    for(i=2;i<=1000;i++)
    {
        if(b[i])
            continue;
        for(j=i+i;j<=1000;j+=i)
            b[j]=1;
    }
}

int main()
{
    int n,k,i,j,v;
    sieve();
    cin>>n;
    if(n==1)
    {
        cout<<0;
        return 0;
    }
    k=0;
    vector<int> vec;
    vector<int>::iterator iter;
    for(i=2;i<=n;i++)
    {
        if(!b[i])
        {
            for(j=i;j<=n;j*=i)
            {
                k++;
                vec.push_back(j);
            }
        }
    }
    cout<<k<<endl;
    for(iter=vec.begin();iter!=vec.end();iter++)
        cout<<*iter<<" ";
    return 0;
}
