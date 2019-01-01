// Problem Link: https://www.spoj.com/problems/PALIN/

#include<bits/stdc++.h>
using namespace std;
#define l 1000001
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    long int t,len,i,j,c9=0,b,c;
    char arr[l];
    cin>>t;
    while(t--)
    {
        cin>>arr;
        len=strlen(arr);
        c9=0;
        for(i=0;i<len;i++)
        {
            if(arr[i]=='9')
                c9++;
        }
        if(c9==len)
        {
            cout<<1;
            for(i=0;i<len-1;i++)
                cout<<0;
            cout<<1<<endl;
            continue;
        }
        b=c=0;
        for(i=0,j=len-1;i<=(len-1)/2;i++,j--)
        {
            if(arr[j]!=arr[i])
            {
                if(arr[j]>arr[i])
                    b=1;
                else
                    b=0;
                arr[j]=arr[i];
            }
            else
                c++;
        }
        if(b||c==((len-1)/2)+1)
        {
            i=(len-1)/2;
            j=len/2;
            bool f=1;
            for(;f;i--,j++)
            {
                if(arr[i]!='9')
                {
                    arr[i]++;
                    if(j!=i)
                        arr[j]++;
                    f=0;
                }
                else
                    arr[i]=arr[j]='0';
            }
        }
        cout<<arr<<endl;
    }
    return 0;
}
 