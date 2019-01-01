// Problem Link: https://www.codechef.com/APRIL17/problems/ROWSOLD

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int t,i,n,sum,pos,ch;
    char arr[100005];
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>arr;
        n=strlen(arr);
        ch=0;
        pos=n-1;
        for(i=n-1;i>=0;i--)
        {
            if(i<(n-1)&&arr[i]=='1'&&arr[i+1]=='0')
                ch++;
            if(arr[i]=='1')
            {
                sum+=(ch+(pos-i));
                pos--;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}
