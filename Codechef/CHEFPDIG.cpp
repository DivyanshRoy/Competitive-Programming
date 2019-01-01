// Problem Link: https://www.codechef.com/SEPT17/problems/CHEFPDIG

#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int t,n,i,ind,dig[11],code,f,s;
	char arr[100005];
	cin>>t;
	
	while(t--)
	{
	    for(i=0;i<=10;i++)
	        dig[i]=0;
	    set<char> se;
	    se.clear();
	    cin>>arr;
	    n=strlen(arr);
	    for(i=0;i<n;i++)
	    {
	        dig[arr[i]-'0']++;
	    }
	    for(char c='A';c<='Z';c++)
	    {
	        code=(int)c;
	        f=c/10;
	        s=c%10;
	        if(f==s&&dig[f]>1)
	        {
	            se.insert(c);
	        }
	        else if(f!=s&&dig[f]>0&&dig[s]>0)
	            se.insert(c);
	    }
	    set<char>::iterator iter;
	    for(iter=se.begin();iter!=se.end();iter++)
	        cout<<*iter;
	    cout<<endl;
	}
	return 0;
}