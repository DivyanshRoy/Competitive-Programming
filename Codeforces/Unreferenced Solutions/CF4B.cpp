#include<bits/stdc++.h>
using namespace std;

int main()
{
    int d,s,i;
    cin>>d>>s;
    int mi[d],ma[d],tmi[d],tma[d];
    for(i=0;i<d;i++)
    {
        scanf("%d %d",&mi[i],&ma[i]);
    }
    tmi[d-1]=mi[d-1];
    tma[d-1]=ma[d-1];
    for(i=d-2;i>=0;i--)
    {
        tmi[i]=tmi[i+1]+mi[i];
        tma[i]=tma[i+1]+ma[i];
    }
    if(tma[0]<s||tmi[0]>s)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES\n";
    for(i=0;i<d-1;i++)
    {
        if(s-tma[i+1]>=mi[i])
        {
            cout<<mi[i]<<" ";
            s-=mi[i];
        }
        else if(s-tmi[i+1]<=ma[i])
        {
            cout<<ma[i]<<" ";
            s-=ma[i];
        }
        else
        {

        }
    }
    cout<<s;
    return 0;
}
