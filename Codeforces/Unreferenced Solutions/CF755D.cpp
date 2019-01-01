#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long int n,k,i,val=1,cnt,j,cur,pre;
    cin>>n>>k;
    vector<long int> arr;
    arr.resize(n+1);
    for(i=0;i<=n;i++)
        arr[i]=0;
    if(2*k>n)
        k=n-k;
    pre=1;
    for(i=0;i<n;i++)
    {
        cur=(pre+k);
        if(cur>n)
            cur%=n;
        if(pre==1&&i)
        {
            while(i++<n)
            {
                cout<<val<<" ";
            }
            return 0;
        }
        cnt=0;
        if(pre<cur)
        {
            for(j=pre+1;j<cur;j++)
            {
                cnt+=arr[j];
            }
        }
        else
        {
            //cout<<pre<<".."<<cur<<endl;
            for(j=pre+1;j<=n;j++)
            {
                //cout<<arr[j]<<endl;
                cnt+=arr[j];
            }
            for(j=1;j<cur;j++)
            {
                //cout<<arr[j]<<endl;
                cnt+=arr[j];
            }
        }
        arr[pre]++;
        arr[cur]++;
        cnt++;
        val+=cnt;
        pre=cur;
        cout<<val<<" ";
    }
    return 0;
}
