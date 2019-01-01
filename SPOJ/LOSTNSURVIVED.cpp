// Problem Link: https://www.spoj.com/problems/LOSTNSURVIVED/

#include <bits/stdc++.h>
using namespace std;
 
long int root[100001],len[100001];
 
multiset<long int> se;
 
long int froot(long int a)
{
    while(a!=root[a])
    a=root[a];
    return a;
}
 
void uni(long int a,long int b)
{
    long int ra,rb,cnt;
    ra=froot(a);
    rb=froot(b);
    if(ra==rb)
        return;
    /*
    cnt=se.count(len[ra]);
    cnt--;
    se.erase(len[ra]);
    while(cnt--)
    {
        se.insert(len[ra]);
    }
    cnt=se.count(len[rb]);
    cnt--;
    se.erase(len[rb]);
    while(cnt--)
    {
        se.insert(len[rb]);
    }
    */
    multiset<long int>::iterator iter;
    iter=se.find(len[ra]);
    se.erase(iter);
    iter=se.find(len[rb]);
    se.erase(iter);
    if(len[ra]>len[rb])
    {
        root[rb]=root[ra];
        len[ra]+=len[rb];
        se.insert(len[ra]);
    }
    else
    {
        root[ra]=root[rb];
        len[rb]+=len[ra];
        se.insert(len[rb]);
    }
}
 
int main()
{
    long int n,i,q,a,b;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        root[i]=i;
        len[i]=1;
        se.insert(1);
    }
    cin>>q;
    multiset<long int>::iterator iter;
    multiset<long int>::reverse_iterator riter;
    for(i=1;i<=q;i++)
    {
        scanf("%ld %ld",&a,&b);
        uni(a,b);
        iter=se.begin();
        riter=se.rbegin();
        cout<<*riter-*iter<<endl;
    }
    return 0;
}