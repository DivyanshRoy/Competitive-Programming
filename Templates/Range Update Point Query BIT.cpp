#define MAX 6000


long long int arr[MAX],arr2[MAX];

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

