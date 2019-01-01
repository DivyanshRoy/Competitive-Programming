#include<bits/stdc++.h>
using namespace std;
#define mx 100005

int main()
{
	long long int n,arr[50][50][50],i,j,k,m,s,sx,sy,ex,ey;
	
	string str;
	cin>>str;
	m = str[0]-'0';
	n = str[2]-'0';
	s = str[4]-'0';
	//cout<<n<<" "<<m<<" "<<s<<endl;
	
	cin>>str;
	sx = str[0]-'0';
	sy = str[2]-'0';
	ex = str[4]-'0';
	ey = str[6]-'0';
	//cout<<sx<<" "<<sy<<" : "<<ex<<" "<<ey<<endl;
	
	for(i=0;i<50;i++)
	{
		for(j=0;j<50;j++)
		{
			for(k=0;k<50;k++)
				arr[i][j][k]=0;
		}
	}
	
	arr[sx+2][sy+2][0]=1;
	
	for(k=0;k<s;k++)
	{
		for(i=0;i<=n;i++)
		{
			for(j=0;j<=m;j++)
			{
					arr[i-1+2][j+2][k+1] += arr[i+2][j+2][k];
			
					arr[i+2][j-1+2][k+1] += arr[i+2][j+2][k];
			
					arr[i+1+2][j+2][k+1] += arr[i+2][j+2][k];	
			
					arr[i+2][j+1+2][k+1] += arr[i+2][j+2][k];	
			}
		}
		
	}
	cout<<arr[ex+2][ey+2][s];
	return 0;
}
