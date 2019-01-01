// Problem Link: https://codeforces.com/contest/907/problem/B

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	char arr[20][20];
	string str[10][10];
	int i,j,x,y;
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<3;j++)
		{
			//cout<<i<<" "<<j<<endl;
			cin>>str[i][j];
			//cin>>arr[i*3][j*3];
		}
	}
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<3;j++)
		{
			for(int k=0;k<3;k++)
			{
				arr[i][j*3+k]=str[i][j][k];
			}
		}
	}
	
	cin>>x>>y;
	
	x%=3;
	y%=3;
	
	if(x==0)
		x=3;
	if(y==0)
		y=3;
	int cnt=0;
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if((i/3)+1==x&&(j/3)+1==y&&arr[i][j]=='.')
				cnt++;
		}
	}
	
	for(i=0;i<9;i++)
	{
		for(j=0;j<9;j++)
		{
			if(cnt==0)
			{
				if(arr[i][j]=='.')
					cout<<"!";
				else
					cout<<arr[i][j];
			}
			else
			{
				if((i/3)+1==x&&(j/3)+1==y)
				{
					if(arr[i][j]=='.')
						cout<<"!";
					else
						cout<<arr[i][j];
				}
				else
					cout<<arr[i][j];
			}
			
			if(j%3==2)
				cout<<" ";
			
		}
		if(i%3==2)
			cout<<endl;
		cout<<endl;
	}
	
	return 0;
}   