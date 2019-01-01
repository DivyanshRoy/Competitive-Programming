// Problem Link: https://www.codechef.com/OCT17/problems/CHEFGP

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long int t,n,i,a,b,ca,cb,pa,pb;
	char arr[100005];
	cin>>t;
	while(t--)
	{
	    cin>>arr>>a>>b;
	    n=strlen(arr);
	    ca=cb=0;
	    for(i=0;i<n;i++)
	    {
	        if(arr[i]=='a')
	            ca++;
	        else if(arr[i]=='b')
	            cb++;
	    }
	    i=0;
	    pa=pb=0;
	    while(i<n)
	    {
	        if(ca>cb)
	        {
	            if(pa==a)
	            {
	                if(pb==b||cb<=0)
	                {
	                    cout<<"*a";
	                    pa=0;
	                    pb=0;
	                    pa++;
	                    ca--;
	                }
	                else
	                {
	                    cout<<"b";
	                    pb++;
	                    pa=0;
	                    cb--;
	                }
	            }
	            else
	            {
	                cout<<"a";
	                pa++;
	                pb=0;
	                ca--;
	            }
	        }
	        else
	        {
	            if(pb==b)
	            {
	                if(pa==a||ca<=0)
	                {
	                    cout<<"*b";
	                    pb=0;
	                    pa=0;
	                    pb++;
	                    ca--;
	                }
	                else
	                {
	                    cout<<"a";
	                    pa++;
	                    pb=0;
	                    ca--;
	                }
	            }
	            else
	            {
	                cout<<"b";
	                pb++;
	                pa=0;
	                cb--;
	            }
	        }
	        i++;
	    }
	    cout<<endl;
	}
	return 0;
}
