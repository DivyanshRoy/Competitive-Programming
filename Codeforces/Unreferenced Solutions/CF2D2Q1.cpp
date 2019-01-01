#include<bits/stdc++.h>
using namespace std;

int main()
{
    int w;
    cin>>w;
    if(w<4)
        cout<<"NO";
    else
    {
        if(w%4==1||w%4==3)
            cout<<"NO";
        else
            cout<<"YES";
    }

    return 0;
}
