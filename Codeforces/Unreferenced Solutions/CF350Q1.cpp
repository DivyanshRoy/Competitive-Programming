#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    if(n%7==0)
        cout<<(n*2)/7<<" "<<(n*2)/7;
    else if(n%7==1)
        cout<<(n*2)/7<<" "<<((n*2)/7)+1;
    else if(n%7==6)
        cout<<(((n+1)*2)/7)-1<<" "<<((n+1)*2)/7;
    else
        cout<<((n-(n%7))*2)/7<<" "<<(((n-n%7)*2)/7)+2;
    return 0;
}
