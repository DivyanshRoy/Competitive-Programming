// Problem Link: https://codeforces.com/contest/898/problem/C

#include<bits/stdc++.h>
using namespace std;
#define MAX 200005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
	
	long long int n,i,m,sz,j,k;
	string name,str;
	
	map<string, set<string> > full,subs;
	set<string> names;
	set<string>::iterator iter1,iter2,iter3;
	cin>>n;
	
	for(i=0;i<n;i++)
	{
		cin>>name;
		names.insert(name);
		cin>>m;
		for(j=0;j<m;j++)
		{
			cin>>str;
			sz=str.size();
			k=0;
			full[name].insert(str);
			
			for(k=1;k<sz;k++)
			{
				subs[name].insert(str.substr(k));
			}
			
		}
		
	}
	
	cout<<names.size()<<endl;
	set<string> ans;
	for(iter1=names.begin();iter1!=names.end();iter1++)
	{
		ans.clear();
		for(iter2=full[*iter1].begin();iter2!=full[*iter1].end();iter2++)
		{
			if(subs[*iter1].find(*iter2)==subs[*iter1].end())
				ans.insert(*iter2);
		}
		cout<<*iter1<<" "<<ans.size()<<" ";
		for(iter3=ans.begin();iter3!=ans.end();iter3++)
			cout<<*iter3<<" ";
		cout<<endl;
		
	}
	
	return 0;
}   