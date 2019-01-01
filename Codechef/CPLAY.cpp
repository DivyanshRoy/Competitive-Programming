// Problem Link: https://www.codechef.com/DEC17/problems/CPLAY

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);
 

	char arr[25];
	int cnt1,cnt2,i;
	while(cin>>arr)
	{
		cnt1=cnt2=0;
		for(i=0;i<10;i++)
		{
			if((i%2)==0)
			{
				if(arr[i]=='1')
					cnt1++;
			}
			else
			{
				if(arr[i]=='1')
					cnt2++;
			}
			int l1,l2;
			l2=(10-i)/2;
			if((i%2)==0)
			{
				l1=l2-1;	
			}
			else
			{
				l1=l2;
			}
			if(cnt1>(cnt2+l2))
			{
				cout<<"TEAM-A "<<i+1<<endl;
				break;
			}
			else if(cnt2>(cnt1+l1))
			{
				cout<<"TEAM-B "<<i+1<<endl;
				break;
			}
		}
		if(i!=10)
			continue;
		if(cnt1!=cnt2)
		{
			if(cnt1>cnt2)
			{
				cout<<"TEAM-A "<<10<<endl;
			}
			else
				cout<<"TEAM-B "<<10<<endl;
		}
		else
		{
			i=10;
			while(i<20)
			{
				if(arr[i]=='1')cnt1++;
				if(arr[i+1]=='1')cnt2++;
				
				if(cnt1!=cnt2)
				{
					if(cnt1>cnt2)
						cout<<"TEAM-A "<<i+2<<endl;
					else
						cout<<"TEAM-B "<<i+2<<endl;
					break;
				}
				else
					i+=2;
			}
			if(i==20)
			{
				cout<<"TIE"<<endl;
			}
		}
	}	
 	
	return 0;
}  