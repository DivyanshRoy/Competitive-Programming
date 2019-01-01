#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,t=0;
    char ch;
    cin>>n>>ch;
    t+=((6*(((n-1)/4)*2)))+(n-1);
    switch(n%4)
    {
        case 0:t+=4;break;
        case 3:t-=2;break;
        case 2:t+=6;break;
    }
    switch(ch)2-
    {
        case 'a':t+=4;break;
        case 'b':t+=5;break;
        case 'c':t+=6;break;
        case 'd':t+=3;break;
        case 'e':t+=2;break;
        case 'f':t+=1;break;
    }
    cout<<t;
    return 0;
}
