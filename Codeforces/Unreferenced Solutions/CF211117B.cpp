#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,a,b,c,i=2;
    cin>>n;
    a=1;
    b=2;
    if(n<=3)
    {
        cout<<max((long long int)1,n);
        return 0;
    }
    c=a+b;
    i=2;
    while(c<n)
    {
        i++;
        c=a+b;
        a=b;
        b=c;
    }
    cout<<i;
    return 0;
}
