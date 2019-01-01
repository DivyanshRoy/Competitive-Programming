// Problem Link: https://www.codechef.com/MAY17/problems/CHEFROUT

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int t,n,i,len;
    char arr[100005];
    bool c,e,s,a;
    cin>>t;
    while(t--)
    {
        cin>>arr;
        len=strlen(arr);
        c=e=s=0;
        a=1;
        for(i=0;i<len;i++)
        {
            if(arr[i]=='C')
            {
                if(e||s)
                {
                    cout<<"no\n";
                    a=0;
                    break;
                }
                else
                    c=1;
            }
            else if(arr[i]=='E')
            {
                if(s)
                {
                    cout<<"no\n";
                    a=0;
                    break;
                }
                else
                    e=1;
            }
            else
            {
                s=1;
            }
        }
        if(a)
            cout<<"yes\n";
    }
    return 0;
}
