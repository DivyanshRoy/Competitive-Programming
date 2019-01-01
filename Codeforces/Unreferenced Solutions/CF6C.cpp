#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,b,a,ca=0,cb=0,i;
    long long int ta=0,tb=0;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    a=0;
    b=n-1;
    while(a<=b)
    {
        if(a==b)
        {
            if(ta==tb||ta<tb)
            {
                ca++;
                a++;
            }
            else
            {
                cb++;
                b--;
            }
            break;
        }
        if(ta==tb)
        {
            ta+=arr[a];
            ca++;
            tb+=arr[b];
            cb++;
            a++;
            b--;
        }
        else if(ta>tb)
        {
            tb+=arr[b];
            cb++;
            b--;
        }
        else
        {
            ta+=arr[a];
            ca++;
            a++;
        }
    }
    cout<<ca<<" "<<cb;
    return 0;
}
