// Problem Link: https://www.codechef.com/LTIME46/problems/BRLADDER

#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int q,a,b;
    cin>>q;
    while(q--)
    {
        scanf("%ld %ld",&a,&b);
        if(a>b)
            swap(a,b);
        if((b==a+1&&a%2==1)||b==a+2)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
