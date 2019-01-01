// Problem Link: https://www.spoj.com/problems/NSTEPS/

#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    int t,x,y;
    cin>>t;
    while(t--)
    {
        cin>>x>>y;
        if(!(x==y||x-2==y))
        {
            cout<<"No Number\n";
            continue;
        }
        if(x%2)
            cout<<x+y-1<<endl;
        else
            cout<<x+y<<endl;
    }
    return 0;
}
 
