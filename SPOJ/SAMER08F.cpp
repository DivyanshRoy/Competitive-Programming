// Problem Link: https://www.spoj.com/problems/SAMER08F/

#include<iostream>
using namespace std;
 
int main()
{
    int n,i;
    long int cnt,num;
    while(1)
    {
        cin>>n;
        if(n==0)
            break;
        cnt=0;
        for(i=1;i<=n;i++)
        {
            num=n-i+1;
            cnt+=(num*num);
        }
        cout<<cnt<<endl;
    }
    return 0;
}
 