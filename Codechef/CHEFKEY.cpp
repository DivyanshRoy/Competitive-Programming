// Problem Link: https://www.codechef.com/OCT16/problems/CHEFKEY

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    long int n,m,c,n1,i,a,b,cnt;
    cin>>T;
    while(T--)
    {
        cin>>n>>m>>c;
        cnt=0;
        n1=c;
        for(i=1;i<=n1;i++)
        {
            if(c%i==0)
            {
                a=i;
                b=c/i;
                if(a<=n&&b<=m)
                    cnt++;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}
