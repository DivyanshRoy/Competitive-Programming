// Problem Link: https://www.codechef.com/OCT17/problems/CHEFCCYL

#include<bits/stdc++.h>
using namespace std;
#define inf 1000000007

int main()
{
	long long int t;
	cin>>t;
		
	while(t--)
	{
	    long long int n,q,i,j,v1,v2,c1,c2,a,w;
	    vector<long long int> len,empt;
	    vector< vector<long long int> > wt,mn1,mn2;
        vector< vector<long long int> > connectors,connectedto,wto;
	    
		len.push_back(0);
		wt.push_back(empt);
		mn1.push_back(empt);
		mn2.push_back(empt);
		cin>>n>>q;
		for(i=1;i<=n;i++)
		{
			cin>>a;
			len.push_back(a);
			wt.push_back(empt);
			mn1.push_back(empt);
			mn2.push_back(empt);
			wt[i].push_back(0);
			mn1[i].push_back(0);
			mn2[i].push_back(0);
			for(j=1;j<=a;j++)
			{
				cin>>w;
				wt[i].push_back(w);
				mn1[i].push_back(inf);
				mn2[i].push_back(inf);
			}
		}
		
		for(i=0;i<=n;i++)
		{
			connectors.push_back(empt);
			connectors[i].push_back(0);
			connectors[i].push_back(0);
			connectors[i].push_back(0);
			connectedto.push_back(empt);
			connectedto[i].push_back(0);
			connectedto[i].push_back(0);
			connectedto[i].push_back(0);
			wto.push_back(empt);
			wto[i].push_back(0);
			wto[i].push_back(0);
			wto[i].push_back(0);
		}
		for(i=1;i<=n;i++)
		{
			cin>>v1>>v2>>w;
			connectors[i][2]=v1;
			connectedto[i][2]=v2;
			wto[i][2]=w;
			
			connectors[(i%n)+1][1]=v2;
			connectedto[(i%n)+1][1]=v1;
			wto[(i%n)+1][1]=w;
			
		}
		
		long long int tmp;
		for(i=1;i<=n;i++)
		{
			j=connectors[i][1];
			tmp=0;
			do
			{
				mn1[i][j]=min(mn1[i][j],tmp);
				tmp+=wt[i][j];
				j=(j%len[i])+1;
			}while(j!=connectors[i][1]);
			
			j=connectors[i][1];
			tmp=0;
			do
			{
				mn1[i][j]=min(mn1[i][j],tmp);
				j--;
				if(j==0)
					j=len[i];
				tmp+=wt[i][j];
			}while(j!=connectors[i][1]);
			
			
			j=connectors[i][2];
			tmp=0;
			do
			{
				mn2[i][j]=min(mn2[i][j],tmp);
				tmp+=wt[i][j];
				j=(j%len[i])+1;
			}while(j!=connectors[i][2]);
			
			j=connectors[i][2];
			tmp=0;
			do
			{
				mn2[i][j]=min(mn2[i][j],tmp);
				j--;
				if(j==0)
					j=len[i];
				tmp+=wt[i][j];
			}while(j!=connectors[i][2]);
		}
		
		vector<long long int> td1,td2;
		long long int dist=0,tl;
		
		td1.push_back(0);
		td2.push_back(0);
		
		for(i=1;i<=n;i++)
		{
			td1.push_back(dist);
			dist+=mn1[i][connectors[i][2]];
			td2.push_back(dist);
			dist+=wto[i][2];
		}
		tl=dist;
				
		while(q--)
		{
			cin>>v1>>c1>>v2>>c2;
			long long int ans=inf,t1,t2;
			
			t1=t2=0;
			
			t1=mn2[c1][v1];
			if(td1[c2]>td2[c1])
			{
				t1+=td1[c2]-td2[c1];
			}
			else
			{
				t1+=tl+td1[c2]-td2[c1];
			}
			t1+=mn1[c2][v2];
			
			t2=mn2[c2][v2];
			if(td1[c1]>td2[c2])
			{
				t2+=td1[c1]-td2[c2];
			}
			else
			{
				t2+=tl+td1[c1]-td2[c2];
			}	
			t2+=mn1[c1][v1];
			cout<<min(t1,t2)<<endl;
		}
	}
	return 0;
}