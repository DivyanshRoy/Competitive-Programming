// Problem Link: https://www.codechef.com/DEC17/problems/VK18

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
 
	
 	long long int val[MAX*20],i,ps[MAX*20],ss[MAX*20],pis[MAX*20],sds[MAX*20],n,sum,odd,even,digit,bc[MAX*20];
 	
 	for(i=0;i<MAX*20;i++)
	{
 		n=i;
		odd=even=0;
		while(n!=0)
		{
			digit=n%10;
			n/=10;
			if(digit&1)
				odd+=digit;
			else
				even+=digit;
		}
		sum=abs(odd-even);
		val[i]=sum;
	}
	
	ps[0]=pis[0]=0;
	
	for(i=1;i<MAX*20;i++)
	{
		ps[i]=ps[i-1]+val[i];
		pis[i]=pis[i-1]+(val[i]*(i-1));
	}
	
	long long int cnt=0;
	ss[(MAX*20)-1]=sds[(MAX*20)-1]=0;
	for(i=(MAX*20)-2;i>=1;i--)
	{
		ss[i]=ss[i+1]+val[i];
		sds[i]=sds[i+1]+(val[i]*cnt);
		bc[i]=cnt;
		cnt++;
	}
	
	long long int t,fp,sp;
	
	cin>>t;
	
	while(t--)
	{
		cin>>n;
		
		fp=pis[1+n]-pis[1];
		
		sp=sds[2+n]-sds[(2*n)+1];
		sp-=(ss[2+n]-ss[(2*n)+1])*(bc[(2*n)+1]);
		cout<<fp+sp<<endl;
	}
	
	return 0;
}  