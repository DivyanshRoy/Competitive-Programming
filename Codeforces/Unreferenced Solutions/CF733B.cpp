#include <bits/stdc++.h>

using namespace std;

#define mi 1000000007
#define rep(i,a,b) for(i=a;i<b;i++)
#define repd(i,a,b,d) for (i=a;i<b;i+=d)
#define repv(i,a,b) for(i=b-1;i>=a;i--)
#define vi vector<int>
#define vl vector<long long int>
#define vvi vector <vector <int> >
#define vvii vector <vector <pair<int,int> > >
#define vvil vector <vector <pair<int,ll> > >
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
ll paw(ll a,ll b);


int main()
{
    long int n,i;
    long long int x,y,d,tx,ty,pos=0,mx=0;
    x=y=0;
    cin>>n;
    int arr[n][2];
    for(i=0;i<n;i++)
    {
        scanf("%d %d",&arr[i][0],&arr[i][1]);
        x+=arr[i][0];
        y+=arr[i][1];
    }
    mx=x-y;
    if(mx<0)
        mx*=-1;
    for(i=0;i<n;i++)
    {
        tx=x;
        ty=y;
        tx-=(arr[i][0]-arr[i][1]);
        ty+=(arr[i][0]-arr[i][1]);
        d=tx-ty;
        if(d<0)
            d*=-1;
        if(d>mx)
        {
            mx=d;
            pos=i+1;
        }
    }
    cout<<pos;
  return 0;
}


ll paw(ll a, ll b)
{
  ll x=((a)%mi),ans=1;
  while(b>0)
    {
      if (b&1)
	ans=(ans*x)%mi;
      x=(x*x)%mi;
      b>>=1;
    }
  return ans;
}
