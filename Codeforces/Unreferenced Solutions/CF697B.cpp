#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int N,i;
    cin>>N;
    int arr[N],mx=0,mn=65536;
    double inv[N]={0},sinv[N]={0};
    cin>>arr[0];
    inv[0]=1/(double)arr[0];
    sinv[0]=(inv[0]);
    mx=arr[0]>mx?arr[0]:mx;
    mn=arr[0]<mn?arr[0]:mn;
    for(i=1;i<N;i++)
    {
        scanf("%d",&arr[i]);
        mx=arr[i]>mx?arr[i]:mx;
        mn=arr[i]<mn?arr[i]:mn;
        inv[i]=1/(double)arr[i];
        sinv[i]=(sinv[i-1]+inv[i]);
    }
    int ano[N+1]={0},bno[N+1]={0},add;
    for(i=N-1;i>=0;i--)
    {
        ano[i]=ano[i+1];
        if(arr[i]==mx)
            ano[i]++;
        bno[i]=bno[i+1];
        if(arr[i]==mn)
            bno[i]++;
    }
    double total=sinv[N-1],mul;
    long double sum=0;
    for(i=0;i<N;i++)
    {
        /*if(i==mx)
            mul=0;
        else
            mul=2/3;
        sum+=((mul*(total-sinv[i])*inv[i]));

        if(i==mn)
            sum+=((mul*bno[i])/((double)arr[i]*(double)mn));
        if(i==mx)
            sum+=(bno[i]/((double)mn*double(i)*(double)3));
        else if(i==mn&&ano[i]>0)
            sum-=((2*ano[i])/((double)mn*(double)mx*(double)3));
        */

        /*
        i==mx
            all values = 0;
            but if there exists any traces of minimum values
            then in those traces we should add min*max/3

        else
            all values=2/3;
            but if there exists any traces of maximum values
                then in those traces we should subtract arr[i]*max*2/3
            also if i==mn & there exists any other traces of mn then we should add arr[i]*mn*2/3
        */
        //1cout<<"\n\nI: "<<i<<endl;
        if(arr[i]==mx)
        {
            sum+=0;
            //cout<<"I=MAX   sum: "<<sum;
            if(bno[i]>0)
            {
                sum+=((double)bno[i]/((double)mn*(double)mx*(double)3));
                //cout<<"\nadded (mincnt>0) : "<<((double)bno[i]/((double)mn*(double)mx*(double)3));
                //cout<<"\nsum = "<<sum<<endl;
            }
        }
        else
        {
            sum+=((2*(total-sinv[i])*inv[i])/3);
            //cout<<"I!=MAX   sum: "<<sum;
            //cout<<"\narr[i] "<<arr[i]<<"  min: "<<mn<<"  max: "<<mx<<endl;
            if(arr[i]==mn)
            {
                if(bno[i]>1)
                {
                    sum+=((double)(bno[i]-1)/((double)mn*(double)mn*(double)3));
                    //cout<<"\nadded (min=true and mincnt>1 = "<<bno[i]<<" : "<<((double)(bno[i]-1)/((double)mn*(double)mn*(double)3));
                    //cout<<"\nsum = "<<sum<<endl;
                }
                if(ano[i]>0)
                {
                    sum-=((double)(ano[i])/((double)mx*(double)mn*(double)3));
                    //cout<<"\nsubtracted: (min=true and maxcnt>0 = )"<<ano[i]<<" : "<<((double)(ano[i])/((double)mx*(double)mn*(double)3));
                    //cout<<"\nsum = "<<sum<<endl;
                }
            }
            else
            {
                //cout<<"ano "<<ano[i]<<endl;
                if(ano[i]>0)
                {
                    sum-=((double)(ano[i]*2)/((double)arr[i]*(double)mx*(double)3));
                    //cout<<"\nsubtracted: (min&max=false and maxcnt>0 = "<<ano[i]<<" : "<<((double)(ano[i]*2)/((double)arr[i]*(double)mx*(double)3));
                    //cout<<"\nsum = "<<sum<<endl;
                }
            }
        }
    }
    sum*=(N-2);
    //cout<<endl<<endl;
    //cout<<sum<<endl;
    long long int val=sum;
    cout<<val;
    return 0;
}
