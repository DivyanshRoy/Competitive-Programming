#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,m,k,i,j,c;
    cin>>n>>m>>k;
    vector <long long int> vec;
    c=1;
    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++,c++)
            if(c!=k)
            vec.push_back(i*j);
            else
                break;
    cout<<i*j;
    return 0;
}
