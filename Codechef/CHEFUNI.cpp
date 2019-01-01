// Problem Link: https://www.codechef.com/DEC17/problems/CHEFUNI

#include<bits/stdc++.h>
using namespace std;
#define MAX 120
  

long long int val(long long int a,long long int b,long long int c,long long int d)
{
	long long int ret=(a*c)+((b-(long long int)2*a)*d);
	return ret;
}


long long int calc(long long int x,long long int y,long long int z,long long int a,long long int b,long long int c,long long int t1)
{
	long long int ans=0;
	ans=(t1*c);
	x-=t1;
	y-=t1;
	z-=t1;
	
	long long int adder=(z-x-y);
	
	if(adder<0)
		adder=0;
	
	ans+=(adder*a);
	z-=adder;
		
	long long int l,r,mid,ta=100000000000000,rest;

	l=0;
	r=(x+y+z)/2;
	rest=(x+y+z);
	ta=min(ta,val(l,rest,b,a));
	ta=min(ta,val(r,rest,b,a));	
		
	while(l<r)
	{
//		cout<<"\t"<<l<<" .. "<<r<<endl;
		mid=(l+r)/2;
		ta=min(ta,val(l,rest,b,a));
		ta=min(ta,val(r,rest,b,a));
		
		if(val(mid,rest,b,a)>val(mid+1,rest,b,a))
		{
			if(mid!=l&&val(mid-1,rest,b,a)<val(mid+1,rest,b,a))
			{
				ta=min(ta,val(mid-1,rest,b,a));
				if(r==mid)
					break;
				r=mid;
			}
			else
			{
				ta=min(ta,val(mid+1,rest,b,a));				
				if(l==mid)
					break;
				l=mid;
			}
		}
		else
		{
			ta=min(ta,val(mid,rest,b,a));			
			if(l==mid)
				break;
			l=mid;
		}
	}
	return ta+ans;
		
}  
  
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int t,n,a,b,c,x,y,z,ans,d,mul,ta,i,j,k;
	long long int l1,r1,l2,r2,m1,m2,t1,t2,t3,adder,s1,s2,s11,s12,s21,s22;
		
	cin>>t;
	while(t--)
	{
		cin>>x>>y>>z>>a>>b>>c;
		if(x>y)
			swap(x,y);
		if(y>z)
			swap(y,z);
		if(x>y)
			swap(x,y);

		
		
		l1=0;
		r1=x;
		ans=10000000000000000;
		
		ans=min(ans,calc(x,y,z,a,b,c,l1));
		ans=min(ans,calc(x,y,z,a,b,c,r1));
			
		
		
		while(l1<r1)
		{
//			cout<<endl;
//			cout<<l1<<" "<<r1<<endl;
			m1=(l1+r1)/2;
			ans=min(ans,calc(x,y,z,a,b,c,l1));
			ans=min(ans,calc(x,y,z,a,b,c,r1));
//			cout<<m1-1<<" "<<m1<<" "<<m1+1<<endl;
//			cout<<calc(x,y,z,a,b,c,m1-1)<<" "<<calc(x,y,z,a,b,c,m1)<<" "<<calc(x,y,z,a,b,c,m1+1)<<endl;
			
			if(m1!=l1)
			{
				if(calc(x,y,z,a,b,c,m1-1)<calc(x,y,z,a,b,c,m1+1))
				{
					ans=min(ans,calc(x,y,z,a,b,c,m1-1));
					if(r1==m1)
						break;
					r1=m1;
				}
				else
				{
					ans=min(ans,calc(x,y,z,a,b,c,m1+1));
					if(l1==m1)
						break;
					l1=m1;
				}
			}
			else if(calc(x,y,z,a,b,c,m1)>calc(x,y,z,a,b,c,m1+1))
			{
				ans=min(ans,calc(x,y,z,a,b,c,m1+1));
				if(l1==m1)
					break;
				l1=m1;
			}
			else
			{
				ans=min(ans,calc(x,y,z,a,b,c,m1));
				if(r1==m1)
					break;
				r1=m1;
			}
			
		}
		cout<<ans<<endl;
	} 

	return 0;
}  	