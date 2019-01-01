// Problem Link: https://codeforces.com/contest/908/problem/B

#include<bits/stdc++.h>
using namespace std;

  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	int n,m,i,j,k,stx,sty,len,cx,cy;
	long int ans=0;
	char means[5];
	char arr[100][100],str[200];
	stx=sty=-1;
	cin>>n>>m;
	
	for(i=0;i<n;i++)
	{
		cin>>arr[i];
	}
	cin>>str;
	len=strlen(str);
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<m;j++)
		{
			if(arr[i][j]=='S')
			{
				stx=i;
				sty=j;
				i=n;
				break;
			}
		}
	}
	
	vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	
	do
	{
		means[vec[0]]='L';
		means[vec[1]]='R';
		means[vec[2]]='U';
		means[vec[3]]='D';
		
		cx=stx;
		cy=sty;
		//swap(cx,cy);
		for(i=0;i<len;i++)
		{
			
			if(means[str[i]-'0']=='U')
			{
				cx--;
			}
			else if(means[str[i]-'0']=='D')
			{
				cx++;
			}
			else if(means[str[i]-'0']=='L')
			{
				cy--;
			}
			else if(means[str[i]-'0']=='R')
			{
				cy++;
			}
			
			if(cx==-1||cy==-1||cx==n||cy==m)
			{
				break;
			}
			else if(arr[cx][cy]=='#')
				break;
			else if(arr[cx][cy]=='E')
			{
				i=len+1;
				break;
			}
		}
		if(i==len+1)
		{
			ans++;
		}
	}while(next_permutation(vec.begin(),vec.end()));
	cout<<ans;
	return 0;
}