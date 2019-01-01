#include<bits/stdc++.h>
using namespace std;

int bit(long long int a)
{
    int cnt=0;
    while(a)
    {
        a>>=1;
        cnt++;
    }
    return cnt;
}

int bitc(long long int a)
{
    long long int n=a&(-a);
    return bit(n);
}

int main()
{
    long long int n,k;
    cin>>n>>k;
    cout<<bitc(k);
    return 0;
}
