//O(V^3)

// Number of vertices in the graph
#define V 100
 
/* Define Infinite as a large enough value. This value will be used
  for vertices not connected to each other */
#define INF 10000000000000000

long long int graph[V][V],dist[V][V];
 
/* A utility function to print solution */
void printSolution(long long int dist[][V])
{
    printf ("Following matrix shows the shortest distances"
            " between every pair of vertices \n");
    for (long long int i = 0; i < V; i++)
    {
        for (long long int j = 0; j < V; j++)
        {
            if (dist[i][j] == INF)
                printf("%10s", "INF");
            else
                printf ("%10d", dist[i][j]);
        }
        printf("\n");
    }
}
 
void floydWarshall ()
{
    /* dist[][] will be the output matrix that will finally have the shortest 
      distances between every pair of vertices */
    long long int i, j, k;
 
    for (i = 0; i < V; i++)
        for (j = 0; j < V; j++)
            dist[i][j] = graph[i][j];
 
    for (k = 0; k < V; k++)
    {
        for (i = 0; i < V; i++)
        {
            for (j = 0; j < V; j++)
            {
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
        }
    }
    printSolution(dist);
}
 
 
int main()
{
    long long int n,m,i,j,u,v,w;
    cin>>n>>m;
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        graph[i][j]=INF;
      }
    }
    
    for(i=0;i<m;i++)
    {
      cin>>u>>v>>w;
      u--;
      v--;
      //If Directed Edges
        //graph[u][v]=w;
      //else
        //graph[u][v]=graph[v][u]=w;
    }
    floydWarshall(graph);
    return 0;
}