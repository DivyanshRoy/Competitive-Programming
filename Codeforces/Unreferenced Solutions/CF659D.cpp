#include<bits/stdc++.h>
using namespace std;

int calc(int x1,int y1,int x2,int y2)
{
    if(x1==x2)
    {
        if(y2>y1)
            return 2;
        else
            return 8;
    }
    else if(y1==y2)
    {
        if(x2>x1)
            return 4;
        else
            return 6;
    }
}

int main()
{
    int n,i;
    cin>>n;
    int x[n],y[n];
    int prev,present,cnt=0;
    bool flag=0;
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&x[i],&y[i]);
        if(i==2)
            flag=1;
        if(flag)
        {
            prev=calc(x[i-1],y[i-1],x[i-2],y[i-2]);
            present=calc(x[i],y[i],x[i-1],y[i-1]);
            if(prev==6&&present==8)
                cnt++;
            else if(prev==2&&present==6)
                cnt++;
            else if(prev==8&&present==4)
                cnt++;
            else if(prev==6&&present==2)
                cnt++;
            else if(prev==4&&present==2)
                cnt++;
        }
    }
    cout<<cnt;
    return 0;
}
