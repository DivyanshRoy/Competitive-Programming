// Problem Link: https://codeforces.com/contest/908/problem/C

#include<bits/stdc++.h>
using namespace std;

  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,rad,x[2000],i,j;
	long double l,r,mid,dist,ny[2000];
	
	cin>>n>>rad;
	
	for(i=1;i<=n;i++)
		cin>>x[i];
		
	for(i=1;i<=n;i++)
	{
		l=(long double)rad;
		r=(long double)10000000;
		
		while((r-l)>=0.000000001)
		{
			bool fine=1;
			mid=(l+r)/(long double)2;	
			for(j=1;j<i;j++)
			{
				if(j<i)
				{
					
					dist=(long double)((x[i]-x[j])*(x[i]-x[j]))+((ny[j]-mid)*(ny[j]-mid));
					dist=sqrt(dist);
//					if(i==2&&j==1)
//						cout<<i<<" y = "<<mid<<" "<<j<<" ny = "<<ny[j]<<" dist = "<<dist<<" vs "<<2*rad<<endl;
					if(dist<(long double)(2*rad))
					{
						fine=0;
						break;
					}
					else if((ny[j]-mid)>=(long double)0.000000001&&abs(x[i]-x[j])<=(2*rad))
					{
						//cout<<i<<" "<<j<<" "<<mid<<" , "<<ny[j]<<endl;
						fine=0;
						break;
					}
				}
			}
			if(fine)
			{
				r=mid;
			}
			else
			{
				l=mid;
			}
		}
		ny[i]=mid;
	}
	for(i=1;i<=n;i++)
		cout<<setprecision(8)<<fixed<<ny[i]<<" ";
	return 0;
}