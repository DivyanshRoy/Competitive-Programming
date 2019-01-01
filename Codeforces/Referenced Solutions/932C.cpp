// Problem Link: https://codeforces.com/contest/932/problem/C

#include <bits/stdc++.h>
using namespace std;

long long int mod(long long int a, long long int b) {
	return ((a%b) + b) % b;
}

long long int extended_euclid(long long int a, long long int b, long long int &x, long long int &y) {
	long long int xx = y = 0;
	long long int yy = x = 1;
	while (b) {
		long long int q = a / b;
		long long int t = b; b = a%b; a = t;
		t = xx; xx = x - q*xx; x = t;
		t = yy; yy = y - q*yy; y = t;
	}
	return a;
}


long long int gcd(long long int a, long long int b) {
	while (b) { long long int t = a%b; a = b; b = t; }
	return a;
}

long long int mod_inverse(long long int a, long long int n) {
	long long int x, y;
	long long int g = extended_euclid(a, n, x, y);
	if (g > 1) return -1;
	return mod(x, n);
}


bool linear_diophantine(long long int a, long long int b, long long int c, long long int &x, long long int &y) {
	if (!a && !b)
	{
		if (c) return false;
		x = 0; y = 0;
		return true;
	}
	if (!a)
	{
		if (c % b) return false;
		x = 0; y = c / b;
		return true;
	}
	if (!b)
	{
		if (c % a) return false;
		x = c / a; y = 0;
		return true;
	}
	long long int g = gcd(a, b);
	if (c % g) return false;
	x = c / g * mod_inverse(a / g, b / g);
	y = (c - a*x) / b;
	return true;
}

long long int ax,ay;
bool solution(int a, int b, int n)
{
    // traverse for all possible values
    for (int i = 0; i * a <= n; i++) {
 
        // check if it is satisfying the equation
        long long int ty=((n - (i * a))/b);
        if ((n - (i * a)) % b == 0&&(ty>=0)) {
            ax=i;
            ay=ty;
			return 1;
        }
    }
 
    return 0;
}


int main()
{
	long long int n,a,b,x,y,arr[1000005],i,j,last=0;
	cin>>n>>a>>b;
	if(!solution(a,b,n))
	{
		cout<<"-1";
		return 0;
	}
	x=ax;
	y=ay;
	
	
	for(i=1;i<=x;i++)
	{
		for(j=last+1;j<=last+a;j++)
		{
			arr[j]=last+1+((j-last)%a);
		}
		last+=a;
	}
	
	for(i=1;i<=y;i++)
	{
		for(j=last+1;j<=last+b;j++)
		{
			arr[j]=last+1+((j-last)%b);
		}
		last+=b;
	}
	for(i=1;i<=n;i++)
		cout<<arr[i]<<" ";
	
	return 0;
}