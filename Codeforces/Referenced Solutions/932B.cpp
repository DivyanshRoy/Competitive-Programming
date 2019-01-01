// Problem Link: https://codeforces.com/contest/932/problem/B

#include <bits/stdc++.h>
using namespace std;
#define MAX 1000005

long long int arr[MAX];

long long int fenwick_tree[MAX][15];

//BIT is 1 indexed.
long long int bit_getSum(long long int index,long long int k)
{
    long long int sum = 0;
    //Add +1 to index if index is 0 based.
    for( ; index>0 ; index -= index & (-index))
    {
        sum += fenwick_tree[index][k];
    }
    return sum;
}
 
long long int bit_range_sum(long long int l,long long int r,long long int k)
{
    long long int ans = bit_getSum(r,k) - bit_getSum(l-1,k);
    return ans;
}

void bit_point_update(long long int n, long long int index, long long int val,long long int k)
{
    //Add +1 to index if index is 0 based.
    for( ; index<=n ; index += index & (-index) )
    {
       fenwick_tree[index][k] += val;
    }
}
 
void constructBITree(long long int n=MAX-2)
{
    for (long long int i=1; i<=n; i++)
    {
    	for(long long int j=0;j<10;j++)
	    	fenwick_tree[i][j] = 0;
	}
}

void precomp()
{
	long long int i,n=1000000,j,pro,tmp,d;
	constructBITree();
	for(i=0;i<10;i++)
	{
		arr[i]=i;
	}
	
	for(i=10;i<MAX;i++)
	{
		tmp=i;
		pro=1;
		while(tmp!=0)
		{
			d=tmp%10;
			if(d!=0)
				pro*=d;
			tmp/=10;
		}
		if(i<=pro)
		{
			cout<<"Error\n";
		}
		arr[i]=arr[pro];
	}
	
	for(i=1;i<MAX;i++)
	{
		bit_point_update(MAX-2,i,1,arr[i]);
	}
	
}

int main()
{
	precomp();
	
	long long int q,l,r,k;
	
	cin>>q;
	
	while(q--)
	{
		cin>>l>>r>>k;
		cout<<bit_range_sum(l,r,k)<<endl;
		
	}
	
	
	return 0;
}