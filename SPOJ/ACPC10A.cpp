// Problem Link: https://www.spoj.com/problems/ACPC10A/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    long int a,b,c;
    while(1)
    {
        cin>>a>>b>>c;
        if(a==0&&b==0&&c==0)
            break;
        if(b-a==c-b)
        {
            cout<<"AP "<<(c+b-a)<<endl;
        }
        else
            cout<<"GP "<<(c*b)/a<<endl;
    }
    return 0;
}