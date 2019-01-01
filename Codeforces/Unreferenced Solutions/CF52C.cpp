#include<bits/stdc++.h>
using namespace std;
const long int siz=200002;

long long int lo[4*siz+1],hi[4*siz+1],table[4*siz+1],delta[4*siz+1];

void prop(long int i)
{
    //if add then use +
    // if something like multiply or xor use * or ^ accordingly
    delta[2*i]+=delta[i];
    delta[2*i+1]+=delta[i];
    delta[i]=0;
}

void update(long int i)
{
    // current case is for min
    // can be changed according to situation
    table[i]=min(table[2*i]+delta[2*i],table[2*i+1]+delta[2*i+1]);
}

void increment(long int i,long int a,long int b,long int val)
{
    if(b<lo[i]||hi[i]<a)
        return;

    if(a<=lo[i]&&hi[i]<=b)
    {
        delta[i]+=val;   //can be changed to * or ^
        return;
    }
    prop(i);

    increment(2*i,a,b,val);
    increment(2*i+1,a,b,val);

    update(i);
}

long long int ret(long int i,long int a,long int b)
{
    if(b<lo[i]||hi[i]<a)
        return (long long int)1000000000000000000;   // return largest value for available datatype

    if(a<=lo[i]&&hi[i]<=b)
    {
        return table[i]+delta[i];   // can be changed to * or ^
    }
    prop(i);

    long long int val,left,right;
    left=ret(2*i,a,b);
    right=ret(2*i+1,a,b);

    val=min(left,right);   //could be sum or max or multiply or xor etc

    update(i);
    return val;
}

void zeros() //to be called
{
    long int i,n=siz*4;
    for(i=0;i<=n;i++)
    {
        table[i]=delta[i]=0;
    }
}

void init(long int i,long int a,long int b) //to be called
{
    lo[i]=a;
    hi[i]=b;
    if(a==b)
        return;
    long int mid=(a+b)/2;
    init(2*i,a,mid);
    init(2*i+1,mid+1,b);
}

void increment(long int a,long int b,long int val) //to be called
{
    increment(1,a,b,val);
}

long long int ret(long int a,long int b) //to be called
{
    return ret(1,a,b);
}

int main()
{
    zeros();
    init(1,0,siz-1);   // for 0 indexed       init(1,1,size); for 1 indexed
    long int n,arr,i,q,a,b,c;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        scanf("%ld",&arr);
        increment(i,i,arr);
    }
    cin>>q;
    char ch;
    while(q--)
    {

        scanf("%ld %ld%c",&a,&b,&ch);
        a++;
        b++;
        if(ch!='\n')
        {
            scanf("%ld",&c);
            if(a>b)
            {
                increment(a,n,c);
                increment(1,b,c);
            }
            else
                increment(a,b,c);
        }
        else
        {
            if(a>b)
            {
                cout<<min(ret(a,n),ret(1,b))<<endl;
            }
            else
                cout<<ret(a,b)<<endl;
        }
    }
    return 0;
}
