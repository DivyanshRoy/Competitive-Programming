#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("B-large.in","r",stdin);
    freopen("output.txt","w",stdout);
	
	long long int t,n,i,j,e,h,s[1005],l,r;
	
	cin>>t;
	
	while(j<=t)
	{
		cin>>e>>n;
		h=0;
		for(i=1;i<=n;i++)
			cin>>s[i];
		sort(s+1,s+n+1);
		
		l=1;
		r=n;
		
		while(l<=r)
		{
			if((e-s[l])>0)
			{
				e-=s[l];
				h++;
				l++;
			}
			else
			{
				if(l==r)
					break;
				if(h>0)
				{
					h--;
					e+=s[r];
					r--;
				}
				else
					break;
			}
		}
		
		cout<<"Case #"<<j<<": "<<h<<endl;
		j++;
	}
	
    return 0;
}
