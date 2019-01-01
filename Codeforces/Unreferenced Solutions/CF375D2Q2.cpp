#include<bits/stdc++.h>
using namespace std;

int calcb(char arr[],int n)
{
    int i,cnt=0,acnt;
    bool start=0,r=0;
    for(i=0;i<n;i++)
    {
        if(arr[i]=='(')
        {
            acnt=0;
            cnt++;
            start =1;
            int j=i+1;
            while(arr[j]=='_')
                j++;
            i=j-1;
            continue;
        }
        else if(arr[i]==')')
        {
            if(acnt==0)
                cnt--;
            start=0;
            if(r)
            {
                cnt--;
            }
        }
        else if(start&&arr[i]=='_')
        {


            if((arr[i-1]!='_'&&arr[i-1]!='('&&arr[i-1]!=')')&&(arr[i+1]!='_'&&arr[i+1]!='('&&arr[i+1]!=')'))
            {
                 cnt++;
            }
            else if(!r&&(arr[i-1]!='_'&&arr[i-1]!='('&&arr[i-1]!=')'))
            {
                cnt++;
                r=1;
            }
            else if((arr[i+1]!='_'&&arr[i+1]!='('&&arr[i+1]!=')'))
            {
                if(r)
                    r=0;
                else
                {
                    cnt++;

                }
            }

        }
        else
        {
            r=0;
            acnt++;
        }

    }
    return cnt;
}

int longest(char arr[],int n)
{
    int i,cnt=0,mx=0;
    bool start=1;
    for(i=0;i<n;i++)
    {
        if(arr[i]!='('&&arr[i]!=')'&&arr[i]!='_'&&start)
            cnt++;
        else
        {
            if(arr[i]=='(')
                start=0;
            else if(arr[i]==')')
                start=1;
            mx=cnt>mx?cnt:mx;
            cnt=0;
        }
    }
    mx=cnt>mx?cnt:mx;
    return mx;
}

int main()
{
    int n,i;
    cin>>n;
    char arr[n];
    cin>>arr;
    cout<<longest(arr,n)<<" "<<calcb(arr,n);
    return 0;
}
