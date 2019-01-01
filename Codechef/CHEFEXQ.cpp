// Problem Link: https://www.codechef.com/DEC17/problems/CHEFEXQ


/*

10 17
1 5 9 10 4 3 7 8 6 2
2 1 0
2 1 1
2 2 5
2 2 6
2 2 4
2 3 9
2 3 13
2 4 3
1 1 16
2 1 0
2 1 1
2 2 5
2 2 6
2 2 4
2 3 9
2 3 13
2 4 3


*/


#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
 
unordered_map<long long int,long long int> ma[320];

void add(long long int a,long long int ind)
{
	unordered_map<long long int,long long int>::iterator iter=ma[ind].find(a);
	
	if(iter==ma[ind].end())
		ma[ind][a]=(long long int)1;
	else
		ma[ind][a]=iter->second+1;
}

void remove(long long int a,long long int ind)
{
	unordered_map<long long int,long long int>::iterator iter=ma[ind].find(a);
	if(iter->second==1)
		ma[ind].erase(iter);
	else
		ma[ind][a]=iter->second-1;
	
}

long long int count(long long int a,long long int ind)
{
	unordered_map<long long int,long long int>::iterator iter=ma[ind].find(a);
	
	if(iter==ma[ind].end())
		return 0;
	else
		return max((long long int)0,iter->second);
}

 
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
 
	long long int n,q,arr[MAX],i,j,a,b,c,partial_xorsum[MAX],sqrt_xorsum[320],sq;
		
	cin>>n>>q;
	sq=sqrt(n);
	for(i=1;i<=n;i++)
	{
		cin>>arr[i];
	}
	
	sqrt_xorsum[0]=partial_xorsum[0]=0;
	i=0;
	for(i=1;i<=n;i++)
	{
		partial_xorsum[i]=partial_xorsum[i-1]^arr[i];
		if((i%sq)==0)
		{
			sqrt_xorsum[i/sq]=sqrt_xorsum[(i/sq)-1]^partial_xorsum[i];
			partial_xorsum[i]=0;
			//cout<<partial_xorsum[i]<<":"<<sqrt_xorsum[i/sq]<<" ";
		}
		else
		{
			add(partial_xorsum[i],(i/sq)+1);
			//cout<<partial_xorsum[i]<<" ";
		}
	}
	//cout<<endl;
	
	while(q--)
	{
		cin>>a>>b>>c;
		if(a==1)
		{
			//update

			i=b;
			long long int xorrer=arr[b]^c,range;
			arr[b]=c;
			
			while(i<=n)
			{
				if((i%sq)==0)
				{
					sqrt_xorsum[i/sq]^=xorrer;
					i+=sq;
				}
				else
				{
					remove(partial_xorsum[i],(i/sq)+1);
					partial_xorsum[i]^=xorrer;
					add(partial_xorsum[i],(i/sq)+1);
					i++;
				}
			}			
		}
		else
		{
			//query
			
			long long int ans=0;
			
			i=0;
			
			while(i<=b)
			{
				if((i+sq)>=b)
				{
					if((i%sq)==0&&i!=0&&i!=b)
					{
						ans+=count((c^sqrt_xorsum[(i/sq)-1]),(i/sq));
			//			cout<<i<<" +|= "<<count(c^sqrt_xorsum[(i/sq)-1],(i/sq))<<" , ";
					}
					if((sqrt_xorsum[i/sq]^partial_xorsum[i])==c&&i!=0)
					{
			//			cout<<sqrt_xorsum[i/sq]<<" ^ "<<partial_xorsum[i]<<" = "<<(sqrt_xorsum[i/sq]^partial_xorsum[i])<<" : ";
						ans++;
			//			cout<<i<<" ++  , ";
					}
					i++;
				}
				else
				{
					if(i!=0)
					{
						ans+=count((c^sqrt_xorsum[(i/sq)-1]),(i/sq));
						if(sqrt_xorsum[(i/sq)]==c)
							ans++;
			//			cout<<i<<" += "<<count(c^sqrt_xorsum[(i/sq)-1],(i/sq))<<" , ";
					}
					i+=sq;
				}
			}
			//cout<<endl;
			cout<<ans<<endl;			
		}
	}
	
	return 0;
} 