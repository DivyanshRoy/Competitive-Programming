// Problem Link: https://www.codechef.com/MARCH17/problems/BANDMATR

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,v;
    long int i,n,z,o,n2,cnt,sub,num;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%ld",&n);
        n2=n*n;
        z=o=0;
        for(i=1;i<=n2;i++)
        {
            scanf("%d",&v);
            if(v)
                o++;
            else
                z++;
        }
        cnt=0;
        num=n;
        while(o>num)
        {
            cnt++;
            if(cnt==1)
            {
                sub=2*(n-1);
            }
            else
                sub-=2;
            num+=sub;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
