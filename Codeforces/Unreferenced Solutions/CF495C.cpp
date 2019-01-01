#include<bits/stdc++.h>
using namespace std;

int main()
{
    char arr[100001];
    long int len,i,b=0,d;
    cin>>arr;
    len=strlen(arr);
    for(i=0;i<len;i++)
    {
        if(arr[i]=='(')
            b++;
        else if(arr[i]==')')
            b--;
    }
    if(b<=0)
    {
        cout<<-1;
        return 0;
    }
    d=b;
    b=0;
    for(i=0;i<len;i++)
    {
        if(arr[i]=='(')
            b++;
        else if(arr[i]==')')
            b--;
        else
        {
            while(arr[i]!='('&&i!=len)
            {
                if(arr[i]==')')
                    b--;
                i++;
            }
            if(b<d)
            {
                cout<<b<<endl;
                d-=b;
                b=0;
            }
            else if(d!=0)
            {
                cout<<d<<endl;
                b-=d;
                d=0;
            }
            i--;
        }
    }
    return 0;
}
