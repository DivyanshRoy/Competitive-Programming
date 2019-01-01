#include<bits/stdc++.h>
using namespace std;


int main()
{
    long int n,t,x,y;
    x=y=0;
    char arr[10];
    cin>>n;
    bool b=0;
    while(n--)
    {
        cin>>t>>arr;
        if(strcmp(arr,"North")==0)
        {
            if(y==0)
            {
                cout<<"NO";
                return 0;
            }
            y-=t;
            //y%=40000;
            if(y<0)
            {
                cout<<"NO";
                return 0;
            }
              //  y*=-1;
        }
        else if(strcmp(arr,"South")==0)
        {
            if(y==20000||b)
            {
                cout<<"NO";
                return 0;
            }
            y+=t;
            //y%=40000;
            if(y>20000)
            {
                cout<<"NO";
                return 0;
            }
              //  y=20000-(y%20000);
        }
        else if(strcmp(arr,"East")==0)
        {
            if(y==0||b)
            {
                cout<<"NO";
                return 0;
            }
            if(y==20000)
            {
                cout<<"NO";
                return 0;
            }
        }
        else if(strcmp(arr,"West")==0)
        {
            if(y==0||b)
            {
                cout<<"NO";
                return 0;
            }
            if(y==20000)
            {
                cout<<"NO";
                return 0;
            }
        }
    }
    if(y==0)
    cout<<"YES";
    else
        cout<<"NO";
	return 0;
}
