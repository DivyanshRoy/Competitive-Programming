// Problem Link: https://codeforces.com/contest/907/problem/A

#include<bits/stdc++.h>
using namespace std;
#define MAX 100005
  
int main()
{
 
	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	int a,b,c,v1,v2,v3,vm;
	
	cin>>v1>>v2>>v3>>vm;
	
	for(a=1;a<=200;a++)
	{
		for(b=1;b<=200;b++)
		{
			for(c=1;c<=200;c++)
			{
				if((vm<=a)&&(2*vm>=a)&&(v3<=a)&&(2*v3>=a)&&(v2<=b)&&(2*v2>=b)&&(v1<=c)&&(2*v1>=c)&&(c>b)&&(b>a)&&(vm<=b)&&(vm<=c)&&(2*vm<b)&&(2*vm<c))
				{
					cout<<c<<endl<<b<<endl<<a;
					return 0;
				}
			}
		}
	}
	cout<<-1;
	return 0;
}  