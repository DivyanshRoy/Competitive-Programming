#include<bits/stdc++.h>
using namespace std;


int main()
{
    long int N,k;
    cin>>N>>k;
    long int arr[N],i,cnt[N];
    for(i=0;i<N;i++)
    {
        scanf("%d",&arr[i]);
            cnt[i]=(((i+1)*(i+2))/2);
    }
    if(k==1)
    {
        cout<<arr[0];
        return 0;
    }
    for(i=0;i<N;i++)
    {
        if(cnt[i]>k)
        {
            k-=(((i-1)*i*(i-1))/4);
            k%=N;
            cout<<arr[k];
            return 0;
        }
    }
    cout<<arr[N-1];
    return 0;
}
