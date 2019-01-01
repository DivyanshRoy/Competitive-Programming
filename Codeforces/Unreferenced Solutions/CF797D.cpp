#include<bits/stdc++.h>
using namespace std;

pair<long long int,long long int> p[100005];
long long int val[100005],arr[100005],ind=0;
bool vis[100005]={0};


void inorder(long long int root)
{
    stack<long long int> st;
    st.push(root);
    long long int l,r,c;
    while(!st.empty())
    {
        c=st.top();
        vis[c]=1;
        st.pop();
        l=p[c].first;
        r=p[c].second;
        if(l!=-1&&(!vis[l]))
        {
            st.push(c);
            st.push(l);
            continue;
        }
        arr[ind++]=val[c];
        if(r!=-1&&(!vis[r]))
        {
            st.push(r);
        }
    }
}

int main()
{
    long long int n,i,root,l,r,v;
    cin>>n;
    root=(n*(n+1))/2;
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld %lld",&v,&l,&r);
        val[i]=v;
        p[i]=make_pair(l,r);
        if(l!=-1)
            root-=l;
        if(r!=-1)
            root-=r;
    }
    inorder(root);
    long long int cv=arr[0],ans=0;
    for(i=1;i<n;i++)
    {
        if(arr[i]>=cv)
        {
            cv=arr[i];
        }
        else
        {
            while(arr[i]<cv&&i<n)
            {
                i++;
                ans++;
            }
            i--;
        }
    }
    cout<<ans;
    return 0;
}
