#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin>>n;
    char arr[n+1];
    cin>>arr;
    long int i,j,len=strlen(arr),cnt=0;
    for(j=0;j<len;j++)
    {
        if(arr[j]=='<')
        {
            cnt++;
        }
        else
            break;
    }
    for(j=len-1;j>=0;j--)
    {
        if(arr[j]=='>')
        {
            cnt++;
        }
        else
            break;
    }
    cout<<cnt;
    return 0;
}
