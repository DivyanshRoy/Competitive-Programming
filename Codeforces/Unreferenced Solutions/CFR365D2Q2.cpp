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
    long int i,n,k;
    long long int sum=0,pos=0;
    cin>>n>>k;
    long int arr[n],val;
    cin>>arr[0];
    sum+=arr[0];
    for(i=1;i<n;i++)
    {
        scanf("%ld",&arr[i]);
        sum+=arr[i];
        pos+=(arr[i]*arr[i-1]);
    }
    pos+=arr[0]*arr[n-1];
    set<long int> s;
    set<long int>::iterator iter;
    for(i=0;i<k;i++)
    {
        scanf("%ld",&val);
        val--;
        pos+=(sum*arr[val]);
        pos-=arr[val]*arr[val];
        if(val>0)
            pos-=arr[val]*arr[val-1];
        else
            pos-=arr[0]*arr[n-1];
        if(val<n-1)
            pos-=arr[val]*arr[val+1];
        else
            pos-=arr[0]*arr[n-1];
        for(iter=s.begin();iter!=s.end();iter++)
            pos-=arr[val]*arr[*iter];
        s.insert(val);
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
