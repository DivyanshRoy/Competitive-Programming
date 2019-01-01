long long int fenwick_tree[500005];

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
 
long long int bit_range_sum(long long int l,long long int r)
{
    long long int ans = bit_getSum(r) - bit_getSum(l-1);
    return ans;
}

void bit_point_update(long long int n, long long int index, long long int val)
{
    //Add +1 to index if index is 0 based.
    for( ; index<=n ; index += index & (-index) )
    {
       fenwick_tree[index] += val;
    }
}
 
void constructBITree(long long int n)
{
        fenwick_tree[i] = 0;
 
    for (long long int i=0; i<n; i++)
        bit_point_update(n, i+1, arr[i]);
 
    //cout<<"Fenwick Tree: \n";
    //for (int i=1; i<=n; i++)
    //      cout << fenwick_tree[i] << " ";
}