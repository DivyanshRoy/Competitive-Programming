long long int dsu_par[1000],dsu_size[1000];


void dsu_initialize(long long int N)
{
    for(long long int i = 0;i<N;i++)
    {
        dsu_par[i] = i ;
        dsu_size[i] = 1;
    }
}


//Parent Array name is dsu_par
long long int dsu_root (long long int i)
{
    while(dsu_par[i] != i)
    {
        dsu_par[i] = dsu_par[ dsu_par[i] ] ; 
        i = dsu_par[i]; 
    }
    return i;
}

//Parent Array name is dsu_par and Size array name is dsu_size
void dsu_union(long long int A,long long int B)
{
    long long int root_A = dsu_root(A);
    long long int root_B = dsu_root(B);
    if(dsu_size[root_A] < dsu_size[root_B ])
    {
        dsu_par[root_A] = dsu_par[root_B];
        dsu_size[root_B] += dsu_size[root_A];
    }
    else
    {
        dsu_par[root_B] = dsu_par[root_A];
        dsu_size[root_A] += dsu_size[root_B];
    }
}

//Returns true if A and B are in same Set
bool dsu_find(long long int A,long long int B)
{
    if(dsu_root(A)==dsu_root(B))
        return true;
    else
        return false;
}