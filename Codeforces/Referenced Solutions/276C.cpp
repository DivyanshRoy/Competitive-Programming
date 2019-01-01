// Problem Link: https://codeforces.com/contest/276/problem/C

#include<bits/stdc++.h>
using namespace std;

#define MAX 200005


long long int arr[MAX];

long long int fenwick_tree[MAX];

//BIT is 1 indexed.
long long int bit_getSum(long long int index)
{
    long long int sum = 0;
    //Add +1 to index if index is 0 based.
    for( ; index>0 ; index -= index & (-index))
    {
        sum += fenwick_tree[index];
    }
    return sum;
}
 
long long int bit_point(long long int index)
{
    return bit_getSum(index);
}

void bit_update(long long int n, long long int index, long long int val)
{
    //Add +1 to index if index is 0 based.
    for( ; index<=n ; index += index & (-index) )
    {
       fenwick_tree[index] += val;
    }
}

void bit_range_update(long long int n,long long int l,long long int r,long long int val)
{
    bit_update(n,l,val);
    bit_update(n,r+1,val*-1);
}
 
void constructBITree(long long int n)
{
    for (long long int i=1; i<=n; i++)
        fenwick_tree[i] = 0;
 
    for (long long int i=1; i<=n; i++)
        bit_range_update(n, i, i, arr[i]);
 
    //cout<<"Fenwick Tree: \n";
    //for (int i=1; i<=n; i++)
    //      cout << fenwick_tree[i] << " ";
}



int main()
{

	//freopen("output.in","r",stdin);
    //freopen("output2.txt","w",stdout);

	long long int n,i,q,l,r,arr2[MAX];
	
	cin>>n>>q;
	arr[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>arr2[i];
		arr[i]=0;
	}
	constructBITree(n);
	
	for(i=1;i<=q;i++)
	{
		cin>>l>>r;
		bit_range_update(n,l,r,1);
	}
	
	pair<long long int,long long int> p[MAX];
	
	for(i=1;i<=n;i++)
	{
		p[i] = { bit_point(i) , i };
	}
	sort(p+1,p+n+1);
	sort(arr2+1,arr2+n+1);
	long long int ans=0;
	
	for(i=1;i<=n;i++)
	{
		ans+=(arr2[i]*p[i].first);
	}
	cout<<ans;
	return 0;
}