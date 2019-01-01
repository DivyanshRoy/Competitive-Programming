#include<bits/stdc++.h>
using namespace std;

long int arr[200000];
map<long int, vector<long int> > m;
map<long int,bool> v;
long long int m1=-1000000000000000000,m2=-1000000000000000000;



int main()
{
    long int n,i,a,b;
    cin>>n;
    for(i=1;i<=n;i++)
        scanf("%ld",&arr[i]);
    for(i=0;i<n-1;i++)
    {
        scanf("%ld %ld",&a,&b);
        m[a].push_back(b);
    }

    for(i=1;i<=n;i++)
    {
        if(!v[i])
            dfs(i);
    }
}
