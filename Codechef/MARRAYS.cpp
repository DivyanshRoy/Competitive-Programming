// Problem Link: https://www.codechef.com/OCT17/problems/MARRAYS

#include <bits/stdc++.h>
using namespace std;
const long long int ninf = -9000000000000000007;

int main() {
	
	long long int t,n,m,i,ans,tmp,j,mxv,mnv,x,cnt=0,add;
	long long int vec[1000005],vmp[1000005],vmn[1000005],st[1000005],sz[1000005],mp[1000005],mn[10000005];
    fflush(stdin);
    fflush(stdout);
	cin>>t;
    add=0;
	while(t--)
	{
	    cin>>n;
	    if(n==1)
	    {
	        cin>>m;
            for(j=0;j<m;j++)
	        {
	            cin>>x;
	        }
	        cout<<0<<endl;
	    }
	    else{
	    ans=0;
	    cnt=0;
        add=0;
	    bool fg=0;
	    for(i=0;i<n;i++)
	    {
	        cin>>m;
            add+=m;
            st[i]=cnt;
            sz[i]=m;
            
            
            
            for(j=0;j<m;j++)
	        {
	            cin>>x;
	            vec[j+st[i]]=x;
	            vmp[j+st[i]]=ninf;
	            vmn[j+st[i]]=ninf;
	        }
	        cnt+=m;
	    }

	    if(add<=10000000){
	        
	    if(fg==1)
	    {
	        cout<<0<<endl;
	        continue;
	    }
        for(i=0;i<sz[0];i++)
	    {
	        vmp[st[0]+i]=0;
	        vmn[st[0]+i]=0;
	    }
	    for(i=0;i<n;i++)
	    {
	        mp[i]=ninf;
	        mn[i]=ninf;
	    }
	    i=0;
	    
	    for(j=st[i];j<st[i]+sz[i];j++)
	    {
	        vmp[j]+=vec[j];
	        mp[i]=max(mp[i],vmp[j]);
	        vmn[j]-=vec[j];
	        mn[i]=max(mn[i],vmn[j]);
	    }
	    long long int ans=0;
	    for(i=1;i<n;i++)
	    {
	        j=0;
	        
	        ans=0;
	        for(j=0;j<sz[i];j++)
	        {
	            long long int ot=(j+sz[i]-1)%sz[i];
	            vmp[st[i]+ot]=mp[i-1]-(i*(vec[st[i]+j]));
	            vmn[st[i]+ot]=mn[i-1]+(i*(vec[st[i]+j]));
	            vmp[st[i]+ot]=max(vmp[st[i]+ot],vmn[st[i]+ot]);
	            vmn[st[i]+ot]=vmp[st[i]+ot];
	            ans=max(ans,vmp[st[i]+ot]);
	        }
	        
	        
	        for(j=st[i];j<st[i]+sz[i];j++)
	        {
	           vmp[j]+=((i+1)*(vec[j]));
	           mp[i]=max(mp[i],vmp[j]);
	           vmn[j]-=((i+1)*(vec[j]));
	           mn[i]=max(mn[i],vmn[j]);
	        }
	    }
	    
	    if(ans<0)
	    {
	        assert(1==0);
	    }
	    cout<<ans<<endl;
	    }
	    else
	     return 100;
	    }
	}
	return 0;
}
