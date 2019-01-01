// Problem Link: https://codeforces.com/contest/907/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,i,len,j,ans=0;
	char arr[MAX],ch,alpha;
	bool ispresent[30],start=0;
	set<char> se;
	
	cin>>n;
	
	for(i=0;i<30;i++)
		ispresent[i]=0;
	
	for(i=1;i<=n;i++)
	{
		set<char>::iterator iter;
		
		cin>>ch>>arr;
		len=strlen(arr);
		
		if(ch=='!'&&start)
		{
			ans++;
			continue;
		}
		else if(ch=='?'&&arr[0]!=alpha&&start)
		{
			ans++;
			continue;
		}
		else if(ch=='?'&&arr[0]==alpha&&start)
			break;
		set<char> tmp;
		for(j=0;j<len;j++)
		{
			tmp.insert(arr[j]);
		}	
		
		set<char> well;
		if(i==1)
		{
			
		
			for(char cha='a';cha<='z';cha++)
			{
				if(ch=='!')
				{
					if(tmp.find(cha)==tmp.end())
					{
						
					}
					else
						se.insert(cha);
				}
				else if(ch=='.')
				{
					if(tmp.find(cha)==tmp.end())
						se.insert(cha);
				}
				else if(ch=='?')
				{
					if(tmp.find(cha)==tmp.end())
						se.insert(cha);
				}
			}

			if(se.size()==1)
			{
				start=1;
				iter=se.begin();
				alpha=*iter;
			}

		
			continue;
		}
		for(iter=se.begin();iter!=se.end();iter++)
		{
			if(ch=='!')
			{
				if(tmp.find(*iter)==tmp.end())
				{
			
				}
				else
					well.insert(*iter);
			}
			else if(ch=='.')
			{
				if(tmp.find(*iter)==tmp.end())
				{
					well.insert(*iter);
				}	
			}
			else if(ch=='?')
			{
				if(*iter!=arr[0])
					well.insert(*iter);
			}
		}
		se.clear();
		
		for(iter=well.begin();iter!=well.end();iter++)
			se.insert(*iter);
			
		if(se.size()==1)
			{
				start=1;
				iter=se.begin();
				alpha=*iter;
			}
		
	}
	cout<<ans;
	return 0;
}