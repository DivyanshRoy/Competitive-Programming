// Problem Link: https://codeforces.com/contest/909/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	set<string> se;
	set<string>::iterator iter;
	string f,l,str;
	
	int i,j,n1,n2;
	
	cin>>f>>l;
	
	n1=f.length();
	n2=l.length();
	
	for(i=1;i<=n1;i++)
	{
		for(j=1;j<=n2;j++)
		{
			//cout<<i<<" "<<j<<endl;
			//cout<<f.substr(0,i)<<" + "<<l.substr(0,j)<<endl;
			str=f.substr(0,i)+l.substr(0,j);
			se.insert(str);
		}
	}
	iter=se.begin();
	cout<<*iter;
	return 0;
}