#include<bits/stdc++.h>
using namespace std;

#define V 110
#define INF 1000000007
long long int tmp,x,y;
void printSolution(long long int dist[][V]);

void floydWarshall (long long int graph[][V])
{
    long long int dist[V][V], i, j, k,m=tmp;
    for (i = 0; i < m; i++)
        for (j = 0; j < m; j++)
            dist[i][j] = graph[i][j];
    for (k = 0; k < m; k++)
    {
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < m; j++)
            {
                if ((dist[i][k] + dist[k][j]) < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
 
void printSolution(long long int dist[][V])
{
    for (long long int i = 0; i < tmp; i++)
    {
        for (long long int j = 0; j < tmp; j++)
        {
    		if(i==0)
    			x+=dist[i][j];
    		else
    			y+=dist[i][j];
	        //if (dist[i][j] == INF)
              //  printf("%7s", "INF");
            //else
              //  printf ("%7d", dist[i][j]);
        }
        //printf("\n");
    }
}
 

long double ans[5][5];

void mult(long double a[5][5],long double b[5][5])
{
	int i,j,k;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			ans[i][j]=(long double)0;
			for(k=0;k<5;k++)
			{
				ans[i][j]=ans[i][j]+(a[i][k]*b[k][j]);
			}
		}
	}
}

void mpow(long double m[5][5],long long int p)
{
	long double c[5][5];
	long int i,j;
	if(p==1)
	{
		for(i=0;i<5;i++)
		{
			for(j=0;j<5;j++)
			{
				ans[i][j]=m[i][j];
			}
		}
		return;
	}
	
	mpow(m,p/2);
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			c[i][j]=ans[i][j];
		}
	}
	
	mult(c,c);
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			c[i][j]=ans[i][j];
		}
	}
	
	if(p%2!=0)
		mult(c,m);
}

int main()
{
	freopen("C-large.in","r",stdin);
    freopen("output.txt","w",stdout);

	long long int u,v,d,n,m,p,i,j,graph[V][V],t,k;
	cin>>t;
	k=1;
	while(k<=t)
	{
	cin>>n>>m>>p;
	tmp=n;
	x=y=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(i==j)
				graph[i][j]=0;
			else
				graph[i][j]=INF;
		}
	}

	for(i=1;i<=m;i++)
	{
		cin>>u>>v>>d;
		graph[u-1][v-1]=min(graph[u-1][v-1],d);
		graph[v-1][u-1]=min(graph[v-1][u-1],d);
	}	
	floydWarshall(graph);
	
	
	
	
	long double a[5][5],c[5][5],inv,inv2;
	inv=(long double)-1/(long double)(n-1);
	inv2=inv*inv;
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			a[i][j]=(long double)0;
		}
	}
	a[0][1]=(long double)1;
	a[1][1]=inv;
	a[1][2]=(long double)1;
	a[2][2]=(long double)1;
	a[3][3]=(long double)1;
	a[4][4]=(long double)1;	
	a[3][0]=(long double)x;
	a[3][1]=(long double)y;
	
	
	mpow(a,p);
	
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			c[i][j]=ans[i][j];
		}
	}
	
	long double an=(long double)0;
	an=(c[3][0]*(long double)1/(long double)(n-1))+(c[3][1]*(long double)0)+(c[3][2]*inv2)+(c[3][3]*(long double)0)+(c[3][4]*(long double)1);
	
	cout<<"Case #"<<k<<": ";
	printf("%.8Lf\n",an);
	k++;
	}
    return 0;
}

