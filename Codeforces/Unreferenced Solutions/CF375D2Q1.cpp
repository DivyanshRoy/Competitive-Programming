#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x1,x2,x3,a,b,c;
    cin>>x1>>x2>>x3;
    if(x2>x1)
        swap(x1,x2);
    if(x3>x1)
        swap(x1,x3);
    if(x3>x2)
        swap(x2,x3);
    cout<<x1-x3;
    return 0;
}
