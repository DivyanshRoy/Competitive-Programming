#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int len,num=0;
    char arr[1000001];
    cin>>arr;
    len=strlen(arr);
    if(len==1)
    {
        num=arr[0]-'0';
        if(num==0)
        {
            cout<<1;
            return 0;
        }
        num%=4;
        switch(num)
        {
        case 0:cout<<6;break;
        case 1:cout<<8;break;
        case 2:cout<<4;break;
        case 3:cout<<2;break;
        }
        return 0;
    }
    else
    {
        num=arr[len-2]-'0';
        num=num*10+(arr[len-1]-'0');
    }
    num%=4;
    switch(num)
    {
        case 0:cout<<6;break;
        case 1:cout<<8;break;
        case 2:cout<<4;break;
        case 3:cout<<2;break;
    }
    return 0;
}
