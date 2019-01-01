#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,m,i;
    cin>>n>>m;
    char name[n][10];
    int reg[n],points[n];
    for(i=0;i<n;i++)
    {
        cin>>name[i]>>reg[i]>>points[i];
    }
    int mxsc[m][3],loc[m][3];
    for(i=0;i<m;i++)
    {
        mxsc[i][0]=mxsc[i][1]=mxsc[i][2]=0;
        loc[i][0]=loc[i][1]=loc[i][2]=-1;
    }
    for(i=0;i<n;i++)
    {
        if(points[i]>mxsc[reg[i]-1][0])
        {
            mxsc[reg[i]-1][2]=mxsc[reg[i]-1][1];
            loc[reg[i]-1][2]=loc[reg[i]-1][1];
            mxsc[reg[i]-1][1]=mxsc[reg[i]-1][0];
            loc[reg[i]-1][1]=loc[reg[i]-1][0];
            mxsc[reg[i]-1][0]=points[i];
            loc[reg[i]-1][0]=i;
        }
        else if(points[i]>mxsc[reg[i]-1][1])
        {
            mxsc[reg[i]-1][2]=mxsc[reg[i]-1][1];
            loc[reg[i]-1][2]=loc[reg[i]-1][1];
            mxsc[reg[i]-1][1]=points[i];
            loc[reg[i]-1][1]=i;
        }
        else if(points[i]>mxsc[reg[i]-1][2])
        {
            mxsc[reg[i]-1][2]=points[i];
            loc[reg[i]-1][2]=i;
        }
    }
    for(i=0;i<m;i++)
    {
        if((mxsc[i][1]==mxsc[i][2])||(mxsc[i][0]==mxsc[i][1]))
            cout<<"?\n";
        else
        {
            cout<<name[loc[i][0]]<<" "<<name[loc[i][1]]<<endl;
        }
    }
    return 0;
}
