// Problem Link: https://www.codechef.com/DEC17/problems/REDBLUE


//Convex Hull Implementation from http://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/
 
#include<bits/stdc++.h>
using namespace std;
  
vector< pair<long long int,long long int> > vecr,vecg;
  
struct Point
{
    long long int x, y;
};
 
Point p0;
 
Point nextToTop(stack<Point> &S)
{
    Point p = S.top();
    S.pop();
    Point res = S.top();
    S.push(p);
    return res;
}
 
long long int swap(Point &p1, Point &p2)
{
    Point temp = p1;
    p1 = p2;
    p2 = temp;
}
 
long long int distSq(Point p1, Point p2)
{
    return (p1.x - p2.x)*(p1.x - p2.x) +
          (p1.y - p2.y)*(p1.y - p2.y);
}
 
long long int orientation(Point p, Point q, Point r)
{
    long long int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
 
    if (val == 0) return (long long int)0;  
    return (val > 0)? (long long int)1: (long long int)2; 
}
 
int compare(const void *vp1, const void *vp2)
{
   Point *p1 = (Point *)vp1;
   Point *p2 = (Point *)vp2;
 
   long long int o = orientation(p0, *p1, *p2);
   if (o == 0)
     return (distSq(p0, *p2) >= distSq(p0, *p1))? -1 : 1;
 
   return (o == 2)? -1: 1;
}
 
void convexHull(Point points[], long long int n,char color)
{
   long long int ymin = points[0].y, min = 0;
   for (long long int i = 1; i < n; i++)
   {
     long long int y = points[i].y;
 
     if ((y < ymin) || (ymin == y &&points[i].x < points[min].x))
        ymin = points[i].y, min = i;
   }
 
   swap(points[0], points[min]);
 
   p0 = points[0];
   qsort(&points[1], n-1, sizeof(Point), compare);
 
   long long int m = 1; 
   for (long long int i=1; i<n; i++)
   {
       while (i < n-1 && orientation(p0, points[i],points[i+1]) == 0)
          i++;
 
 
       points[m] = points[i];
       m++;  
   }
 
   if (m < 3) return;
 
   stack<Point> S;
   S.push(points[0]);
   S.push(points[1]);
   S.push(points[2]);
 
   for (long long int i = 3; i < m; i++)
   {
      while (orientation(nextToTop(S), S.top(), points[i]) != 2)
         S.pop();
      S.push(points[i]);
   }
 
   while (!S.empty())
   {
       	Point p = S.top();
       	if(color=='r')
    		vecr.push_back({p.x,p.y});
    	else
    		vecg.push_back({p.x,p.y});
       //cout << "(" << p.x << ", " << p.y <<")" << endl;
       S.pop();
   }
}
 
int main()
{
    Point red[1005],green[1005];
    long long int t,n,m,i,rsz,gsz,rn,rp,gn,gp,j,k,p1x,p1y,p2x,p2y,ans=10000000,ta;
    long double me,c,res;
    cin>>t;
    while(t--)
    {
    	ans=10000000;
    	vecr.clear();
    	vecg.clear();
    	cin>>n>>m;
    	for(i=0;i<n;i++)
    		cin>>red[i].x>>red[i].y;
    	for(i=0;i<m;i++)
    		cin>>green[i].x>>green[i].y;
    		
    	convexHull(red, n,'r');
    	convexHull(green, m,'g');
    	
    	rsz=vecr.size();
    	gsz=vecg.size();
    	
		long long int r3,r4;
    	//if(rsz!=1)
		{
	    	for(i=0;i<100;i++)
	    	{
	    		r3=rand()%n;
	    		p1x=red[r3].x;
	    		p1y=red[r3].y;
	    		
	    		for(k=0;k<100;k++)
	    		{
	    			r4=rand()%n;
	    			p2x=red[r4].x;
	    			p2y=red[r4].y;
	    				
	    			if(p1x==p2x&&p1y==p2y)
	    				continue;
				
					me=(long double)(p2y-p1y)/(long double)(p2x-p1x);
		    		c=(long double)p2y-me*(long double)p2x;
		    		
		    		rn=rp=gn=gp=0;
		    		
		    		for(j=0;j<n;j++)
		    		{
		    			if(red[j].x==p1x&&red[j].y==p1y)
		    				continue;
		    			if(red[j].x==p2x&&red[j].y==p2y)
		    				continue;
		    			res=(long double)red[j].y-me*(long double)red[j].x-c;
		    			if(res<0.000000000)
		    				rn++;
		    			else
		    				rp++;
					}
					
					for(j=0;j<m;j++)
		    		{
		    			if(green[j].x==p1x&&green[j].y==p1y)
		    				continue;
		    			if(green[j].x==p2x&&green[j].y==p2y)
		    				continue;
		    			res=(long double)green[j].y-me*(long double)green[j].x-c;
		    			if(res<0.000000000)
		    				gn++;
		    			else
		    				gp++;
					}
					//cout<<"R: "<<p1x<<" "<<p1y<<" ,, "<<p2x<<" "<<p2y<<endl;
					ta=min(gn+rp,gp+rn);
					//cout<<"rn = "<<rn<<" , rp = "<<rp<<" , gn = "<<gn<<" , gp = "<<gp<<endl;
					//cout<<ta<<endl;
					ans=min(ans,ta);
					
				}
			}
		}
		
		long long int r;
	    	
		//if(rsz!=1&&)
		{
	    	for(i=0;i<100;i++)
	    	{
	    		r=rand()%n;
	    		p1x=red[r].x;
	    		p1y=red[r].y;
	    		
	    		for(k=0;k<m;k++)
	    		{
	    			p2x=green[k].x;
	    			p2y=green[k].y;
	    				
	    			if(p1x==p2x&&p1y==p2y)
	    				continue;
				
					me=(long double)(p2y-p1y)/(long double)(p2x-p1x);
		    		c=(long double)p2y-me*(long double)p2x;
		    		
		    		rn=rp=gn=gp=0;
		    		
		    		for(j=0;j<n;j++)
		    		{
		    			if(red[j].x==p1x&&red[j].y==p1y)
		    				continue;
		    			if(red[j].x==p2x&&red[j].y==p2y)
		    				continue;
		    			res=(long double)red[j].y-me*(long double)red[j].x-c;
		    			if(res<0.000000000)
		    				rn++;
		    			else
		    				rp++;
					}
					
					for(j=0;j<m;j++)
		    		{
		    			if(green[j].x==p1x&&green[j].y==p1y)
		    				continue;
		    			if(green[j].x==p2x&&green[j].y==p2y)
		    				continue;
		    			res=(long double)green[j].y-me*(long double)green[j].x-c;
		    			if(res<0.000000000)
		    				gn++;
		    			else
		    				gp++;
					}
					//cout<<"R: "<<p1x<<" "<<p1y<<" ,, "<<p2x<<" "<<p2y<<endl;
					ta=min(gn+rp,gp+rn);
					//cout<<"rn = "<<rn<<" , rp = "<<rp<<" , gn = "<<gn<<" , gp = "<<gp<<endl;
					//cout<<ta<<endl;
					ans=min(ans,ta);
					
				}
			}
		}
		
		long long int r1,r2;
		//if(gsz!=1)
		{
			for(i=0;i<100;i++)
	    	{
	    		r1=rand()%m;
	    		p1x=green[r1].x;
	    		p1y=green[r1].y;
	    		
				for(k=0;k<100;k++)
				{
					r2=rand()%m;
					p2x=green[r2].x;
	    			p2y=green[r2].y;
	    			
	    			if(p1x==p2x&&p1y==p2y)
	    				continue;
	    		
				
					me=(long double)(p2y-p1y)/(long double)(p2x-p1x);
		    		c=(long double)p2y-me*(long double)p2x;
		    		
		    		rn=rp=gn=gp=0;
		    		
		    		for(j=0;j<m;j++)
		    		{
		    			if(green[j].x==p1x&&green[j].y==p1y)
		    				continue;
		    			if(green[j].x==p2x&&green[j].y==p2y)
		    				continue;
		    			res=(long double)green[j].y-me*(long double)green[j].x-c;
		    			if(res<0.0000000001)
		    				gn++;
		    			else
		    				gp++;
					}
					
					for(j=0;j<n;j++)
		    		{
		    			if(red[j].x==p1x&&red[j].y==p1y)
		    				continue;
		    			if(red[j].x==p2x&&red[j].y==p2y)
		    				continue;
		    			res=(long double)red[j].y-me*(long double)red[j].x-c;
		    			if(res<0.0000000001)
		    				rn++;
		    			else
		    				rp++;
					}
					//cout<<"G: "<<p1x<<" "<<p1y<<" ,, "<<p2x<<" "<<p2y<<endl;
					ta=min(gn+rp,gp+rn);
					//cout<<"rn = "<<rn<<" , rp = "<<rp<<" , gn = "<<gn<<" , gp = "<<gp<<endl;
					//cout<<ta<<endl;
					ans=min(ans,ta);
					
				}
			}
		}
		
		for(i=0;i<rsz;i++)
    	{
    		p1x=vecr[i].first;
    		p1y=vecr[i].second;
    		p2x=vecr[(i+1)%rsz].first;
    		p2y=vecr[(i+1)%rsz].second;
    		
    		me=(long double)(p2y-p1y)/(long double)(p2x-p1x);
    		c=(long double)p2y-me*(long double)p2x;
    		
    		rn=rp=gn=gp=0;
    		
    		for(j=0;j<n;j++)
    		{
    			if(red[j].x==p1x&&red[j].y==p1y)
    				continue;
    			if(red[j].x==p2x&&red[j].y==p2y)
    				continue;
    			res=(long double)red[j].y-me*(long double)red[j].x-c;
    			if(res<0.000000000)
    				rn++;
    			else
    				rp++;
			}
			
			for(j=0;j<m;j++)
    		{
    			res=(long double)green[j].y-me*(long double)green[j].x-c;
    			if(res<0.000000000)
    				gn++;
    			else
    				gp++;
			}
			ta=min(gn+rp,gp+rn);
			ans=min(ans,ta);
		}
		
		
		for(i=0;i<gsz;i++)
    	{
    		p1x=vecg[i].first;
    		p1y=vecg[i].second;
    		p2x=vecg[(i+1)%gsz].first;
    		p2y=vecg[(i+1)%gsz].second;
    		
    		me=(long double)(p2y-p1y)/(long double)(p2x-p1x);
    		c=(long double)p2y-me*(long double)p2x;
    		
    		rn=rp=gn=gp=0;
    		
    		for(j=0;j<m;j++)
    		{
    			if(green[j].x==p1x&&green[j].y==p1y)
    				continue;
    			if(green[j].x==p2x&&green[j].y==p2y)
    				continue;
    			res=(long double)green[j].y-me*(long double)green[j].x-c;
    			if(res<0.000000000)
    				gn++;
    			else
    				gp++;
			}
			
			for(j=0;j<n;j++)
    		{
    			res=(long double)red[j].y-me*(long double)red[j].x-c;
    			if(res<0.000000000)
    				rn++;
    			else
    				rp++;
			}
			ta=min(gn+rp,gp+rn);
			ans=min(ans,ta);
		}
		
		
		
		if(ans!=10000000)
			cout<<ans<<endl;
		else
			cout<<0<<endl;
	}
    
	return 0;
} 