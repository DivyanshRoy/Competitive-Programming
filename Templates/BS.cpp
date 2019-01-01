/*
Example: Array of 10 elements with elements given below
NOTE: 0 INDEXING IS FOLLOWED HERE
n = 10
Values:  1  2  3  4  10 10 10 15 20 25
Indexes: 0  1  2  3  4  5  6  7  8  9
bs(10): 6
bs(-10): 0
bs(100): 9
bs(6): 3
lb(10): 3
lb(-10): 0
lb(100): 9
lb(6): 3
ub(10): 6
ub(-10): 0
ub(100): 9
ub(6): 3
*/

long long int bs_arr[100];

bool bs_eval()
{
    if()
}

bool bs_lb_eval(long long int m,long long int c)
{
    if(bs_arr[m]<c)
        return true;
    else
        return false;
}

//If c is present or not: Returns Maximum Index with value smaller than c
//See example for values not in boundary
//l=0 and r=n for default case (0 indexed)
//Check if bs_arr[returned index] matches value of c
long long int bs_lower_bound(long long int n,long long int c,long long int l,long long int r) {

    while ( r-l > 1) {
        long long int m = (r-l)/2+l;
        if (bs_lb_eval(m,c)) 
            l = m+1; 
        else 
            r = m;
    }
    return l;
}
 
bool bs_ub_eval(long long int m,long long int c)
{
    if(bs_arr[m]<=c)
        return true;
    else
        return false;
}

//If c is present : Returns Maximum Index with the value of c
//else : Returns Maximum Value Smaller than c
//See example for values not in boundary
//l=0 and r=n for default case (0 indexed)
//Check if bs_arr[returned index] matches value of c
long long int bs_upper_bound(long long int n, long long int c,long long int l,long long int r) {

    while ( r-l > 1 ) {
        long long int m = (r-l)/2+l;
        if (bs_ub_eval(m,c)) 
            l = m+1; 
        else 
            r = m;
    }
    return l;
}

bool bs_bs_eval(long long int m,long long int c)
{
    if(bs_arr[m]<=c)
        return true;
    else
        return false;
}

//If c is present : Returns an index where it is present
//else : Returns an index with value lower than c
//See example for values not in boundary
//l=0 and r=n for default case (0 indexed)
//Check if bs_arr[returned index] matches value of c
long long int bs_binary_search(long long int n,long long int l, long long int r, long long int c)
{
    long long int m;
 
    while( r - l > 1 )
    {
        m = l + (r-l)/2;
 
        if(bs_bs_eval(m,c))
            l = m;
        else
            r = m;
    }
    return l;
}


