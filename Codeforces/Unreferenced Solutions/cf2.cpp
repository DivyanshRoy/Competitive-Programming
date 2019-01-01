#include<iostream>
using namespace std;

int main()
{
    int N;
    cin>>N;
    long int arr[N][N],i,j,i1,j1;
    long long int s1,s2,s3,s4,d;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
            cin>>arr[i][j];
    }
    for(i=0;i<N;i++)
    {
        for(j=0;j<N;j++)
        {
            if(arr[i][j]==0)
            {
                s1=s2=s3=s4=0;
                if(i==j&&i==N-j-1)
                {
                    i1=i;
                    for(j1=0;j1<N;j1++)
                        s1+=arr[i1][j1];
                    j1=j;
                    for(i1=0;i1<N;i1++)
                        s2+=arr[i1][j1];
                    for(i1=0;i1<N;i1++)
                        s3+=arr[i1][i1];
                    for(i1=0;i1<N;i1++)
                        s4+=arr[i1][N-i1-1];
                    if(s1==s2&&s2==s3&&s3==s4)
                    {

                    }
                    else
                    {
                        cout<<"-1";
                        return 0;
                    }
                }
                else if(i==j)
                {
                 i1=i;
                    for(j1=0;j1<N;j1++)
                        s1+=arr[i1][j1];
                    j1=j;
                    for(i1=0;i1<N;i1++)
                        s2+=arr[i1][j1];
                    for(i1=0;i1<N;i1++)
                        s3+=arr[i1][i1];
                    if(s1==s2&&s2==s3)
                    {

                    }
                    else
                    {
                        cout<<"-1";
                        return 0;
                    }
                }
                else if(i==N-j-1)
                {
                    i1=i;
                    for(j1=0;j1<N;j1++)
                        s1+=arr[i1][j1];
                    j1=j;
                    for(i1=0;i1<N;i1++)
                        s2+=arr[i1][j1];
                    for(i1=0;i1<N;i1++)
                        s4+=arr[i1][N-i1-1];
                    if(s1==s2&&s2==s4)
                    {

                    }
                    else
                    {
                        cout<<"-1";
                        return 0;
                    }
                }
                else{
                    i1=i;
                    for(j1=0;j1<N;j1++)
                        s1+=arr[i1][j1];
                    j1=j;
                    for(i1=0;i1<N;i1++)
                        s2+=arr[i1][j1];
                    if(s1==s2)
                    {

                    }
                    else
                    {
                        cout<<"-1";
                        return 0;
                    }
                }
                s1=s2=0;
                if(i==0)
                i1=i+1;
                else
                    i1=i-1;
                for(j1=0;j1<N;j1++)
                    s1+=arr[i1][j1];
                i1=i;
                for(j1=0;j1<N;j1++)
                    s2+=arr[i1][j1];
                d=s1-s2;
                if(d==0)
                    cout<<"-1";
                else
                cout<<d;
                i=N;
                break;
            }
        }
    }

    return 0;
}
