#include<bits/stdc++.h>
using namespace std;

int main()
{
    int h,i;
    long long int tot=1,n,sum=0,next;
    cin>>h>>n;
    for(i=0;i<h;i++)
        tot<<=1;
    while(n!=1)
    {
        next=tot>>1;
        if(n<=next)
        {
//            sum++;
            tot=next;
        }
        else
        {
            n-=next;
            sum+=tot;
            cout<<"\n+"<<tot;
            tot=next;
        }
        h--;
        cout<<h<<endl;
    }
    cout<<i-h<<" "<<i<<endl;

    //if((i-h)>0&&(i-h)%2==0)
      //  sum+=(i);
    //else if((i-h)>0)
      //  sum++;
    //else
        //sum++;
    cout<<sum;
    return 0;
}
