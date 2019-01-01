// Problem Link: https://www.codechef.com/OCT17/problems/PERFCONT

#include <iostream>
using namespace std;

int main() {
	long int t,n,p,x,i,c,h;
	cin>>t;
	while(t--)
	{
	    c=h=0;
	    cin>>n>>p;
	    for(i=1;i<=n;i++)
	    {
	        cin>>x;
	        if(x>=(p/2))
	            c++;
	       else if(x<=(p/10))
	            h++;
	    }
	    if(c==1&&h==2)
	        cout<<"yes\n";
	    else 
	        cout<<"no\n";
	}
	return 0;
}
