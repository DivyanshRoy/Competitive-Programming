#include<bits/stdc++.h>
using namespace std;

long int n,occ[200001];
unordered_map<long int, vector<long int> > ma;
unordered_map<long int, set<long int> > ms;
unordered_map<long long int , long int> mc;

long long int make_pair(long int a,long int b)
{
    return a+b+(a*b);
}
void dfs(long int pre,long int cur,long int cnt)
{
    vector<long int>::iterator iter;
    if(cnt!=0)
        ms[cur].insert(cnt);
    for(iter=ma[cur].begin();iter!=ma[cur].end();iter++)
    {
        if(*iter==pre)
            continue;
        dfs(cur,*iter,cnt+1);
    }
}

int main()
{
    long int mn,i,u,v;
    cin>>n;
    for(i=1;i<n;i++)
    {
        scanf("%ld %ld",&u,&v);
        ma[u].push_back(v);
        ma[v].push_back(u);
        occ[u]++;
        occ[v]++;
    }
    long int ccnt=0;
    for(i=1;i<=n;i++)
    {
        if(occ[i]<=2)
            ccnt++;
    }
    if(ccnt==n)
    {
        if(n%2==0)
            cout<<n-1;
        else
            cout<<n/2;
        return 0;
    }

    for(i=1;i<=n;i++)
    {
        if(occ[i]==1)
            dfs(0,i,0);
    }
    mn=1000000;
    long int sz,tempo,t1,t2;
    bool bo;
    set<long int>::iterator iter,iter1;
    vector<long int>::iterator iter2;
    for(i=1;i<=n;i++)
    {
        if(occ[i]!=1)
        {
            sz=ms[i].size();
            if(sz>2)
                continue;
            iter=ms[i].begin();
            if(sz==1)
                mn=min(mn,*iter);
            else if(sz==2)
            {

                iter1=iter;
                iter1++;
                t1=*iter;
                t2=*iter1;
                tempo=t1+t2;
                bo=0;
                for(iter2=ma[i].begin();iter2!=ma[i].end();iter2++)
                {
                    if(ms[*iter2].find(t1-1)!=ms[*iter2].end()&&ms[*iter2].find(t2-1)!=ms[*iter2].end())
                    {
                        bo=1;
                        break;
                    }
                }
                if(bo)
                    continue;
                mn=min(mn,tempo);
            }
        }
    }
    if(mn==1000000)
        cout<<"-1";
    else
        cout<<mn;
    return 0;
}
