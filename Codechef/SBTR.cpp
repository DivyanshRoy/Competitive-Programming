// Problem Link: https://www.codechef.com/JUNE17/problems/SBTR

#include<bits/stdc++.h>
using namespace std;

long long int n,m,arr[10005],i,a,b,no,cur,mn;
bool is[10005],ia[10005];
vector<long long int> vec[10005];

void dfs(long long int cur,long long int par)
{
    vector<long long int>::iterator iter;
    long long int av=0;
    for(iter=vec[cur].begin();iter!=vec[cur].end();iter++)
    {
        if(*iter==par)
            continue;
        if(is[*iter])
            return;
        av++;
    }
    is[cur]=1;
    if(av>0)
    {
        for(iter=vec[cur].begin();iter!=vec[cur].end();iter++)
        {
            if(*iter==par)
                continue;
            dfs(*iter,cur);
            return;
        }
    }

}

int main()
{
    cin>>n>>m;
    for(i=1;i<=n;i++)
        is[i]=0;
    arr[0]=0;
    cur=0;
    for(i=1;i<=n;i++)
    {
        cin>>arr[i];
        if(arr[i]>arr[cur])
            cur=i;
    }
    for(i=1;i<=m;i++)
    {
        cin>>a>>b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    no=n;
    mn=no;
    if(n<=40){
    for(long long int jt=1;jt<=n;jt++)
    {
        no=n;
        for(i=1;i<=n;i++)
            is[i]=0;
        dfs(jt,0);
        for(i=1;i<=n;i++)
        {
            if(is[i])
                no--;
        }
        if(no<mn)
        {
            mn=no;
            for(i=1;i<=n;i++)
                ia[i]=is[i];
        }
    }
    }
    dfs(rand()%n+1,0);
    cout<<mn<<endl;
    for(i=1;i<=n;i++)
    {
        if(!ia[i])
            cout<<i<<" ";
    }
    return 0;
}
