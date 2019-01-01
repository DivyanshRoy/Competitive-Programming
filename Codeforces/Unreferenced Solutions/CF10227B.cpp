#include<bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    long int val,cval,k,arr[50],j,n,i,c,cnt;
    bool b[50];
    while((cin>>num)&&num)
    {
        for(i=0;i<num;i++)
            scanf("%ld",&arr[i]);
        cin>>k;
        c=5;
        for(i=k;c;i++)
        {
            cnt=0;
            for(j=0;j<num;j++)
            {
                b[j]=0;
                val=i;
                n=(sqrt((4-arr[j])*(4-arr[j])+8*i*(arr[j]-2))+(arr[j]-4))/(2*(arr[j]-2));
                cval=(n*(2+(n-1)*(arr[j]-2)))>>1;
                if(val==cval)
                {
                    cnt++;
                    b[j]=1;
                }
            }
            if(cnt>=2)
            {
                cout<<i<<":";
                for(j=0;j<num;j++)
                {
                    if(b[j])
                        cout<<arr[j]<<" ";
                }
                cout<<endl;
                c--;
            }
        }
    }
    return 0;
}
