// Problem Link: https://www.codechef.com/OCT17/problems/MEX

#include <bits/stdc++.h>
using namespace std;

int main() {
	
	long int t,n,k,i,a,m;
	set<long int> se;
	
	cin>>t;
	while(t--)
	{
	    se.clear();
	    cin>>n>>k;
	    for(i=1;i<=n;i++)
	    {
	        cin>>a;
	        se.insert(a);
	    }
	    m=0;
	    while(1)
	    {
	       if(se.find(m)==se.end())
	       {
	           if(k==0)
	            break;
	           k--;
	           m++;
	       }
	       else
	        m++;
	    }
	    cout<<m<<endl;
	}
	
	return 0;
}
