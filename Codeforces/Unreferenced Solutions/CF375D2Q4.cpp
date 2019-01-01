#include<bits/stdc++.h>
using namespace std;

int arr[100][100];
char in[100][100];
bool visited[100][100];
long int n,m,k,cnt=1000,num;
static long int freq[1000];

class node
{
public:
    node(long int a,long int b,int c)
    {
        i=a;
        j=b;
        ch=c;
    }
    long int i,j;
    int ch;
};

stack<node> sta;

void DFS()
{
    long int i,j;
    int ch;
    while(sta.empty()==false)
    {
        node temp=sta.top();
        sta.pop();
        i=temp.i;
        j=temp.j;
        ch=temp.ch;
        if(i<0||i>n-1||j<0||j>m-1)
        {
            continue;
        }

        if(visited[i][j])
        {
            continue;
        }
        visited[i][j]=1;
        if(arr[i][j]==0)
        {
            if(ch!=100)
            {
                freq[ch-1000]++;
            }
            arr[i][j]=ch;
            sta.push(node(i,j+1,ch));
            sta.push(node(i-1,j,ch));
            sta.push(node(i+1,j,ch));
            sta.push(node(i,j-1,ch));
        }
    }
    return;
}

void locateLake()
{
    long int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(!visited[i][j])
            if(arr[i][j]==0)
            {
                freq[cnt-1000]=1;
                arr[i][j]=cnt++;
                sta.push(node(i,j+1,arr[i][j]));
                sta.push(node(i-1,j,arr[i][j]));
                sta.push(node(i+1,j,arr[i][j]));
                sta.push(node(i,j-1,arr[i][j]));

                DFS();
            }
    num=cnt-1000;
}

void resetVisited()
{
    long int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            visited[i][j]=0;
}



long int getMax(long int arr[], long int n)
{
    long int max = arr[0];
    for (long int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(long int arr[],long int arr1[], long int n, long int exp)
{
    long int output[n],o[n];
    long int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        o[count[(arr[i] / exp) % 10] - 1] = arr1[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
    {
        arr[i] = output[i];
        arr1[i]=o[i];
    }
}

void radixsort(long int arr[],long int arr1[], long int n)
{
    long int m = getMax(arr, n);
    for (long int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr,arr1, n, exp);
}

void bsort(long int arr[],long int arr1[],long int n)
{
    long int i,j;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-i-1;j++)
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                swap(arr1[j],arr1[j+1]);
            }
    }
}

void output()
{
    long int i,j,order[num];
    for(i=0;i<num;i++)
        order[i]=i;
    bsort(freq,order,num);
    set<int> s;
    long int val=0;
    for(i=0;i<num-k;i++)
    {
        val+=freq[i];
        s.insert(order[i]+1000);
    }
    cout<<val<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]==100)
                cout<<".";
            else if(arr[i][j]>=1000)
            {
                if(s.find(arr[i][j])!=s.end())
                    cout<<"*";
                else
                    cout<<".";
            }
            else
                cout<<"*";
        }
        cout<<endl;
    }
}

void locateOcean()
{
    long int i,j;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(i==0||i==n-1||j==0||j==m-1)
                if(arr[i][j]==0)
                {
                    arr[i][j]=100;

                    sta.push(node(i,j+1,arr[i][j]));
                    sta.push(node(i-1,j,arr[i][j]));
                    sta.push(node(i+1,j,arr[i][j]));
                    sta.push(node(i,j-1,arr[i][j]));

                    DFS();

                }
}

int main()
{
    cin>>n>>m>>k;
    //n=m=50;
    //k=43;
    long int i,j;
    //for(i=0;i<n;i++)
    //    if(i%2)
      //      strcpy(in[i],"*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.");
    //    else
      //      strcpy(in[i],".*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*.*");
    for(i=0;i<n;i++)
        cin>>in[i];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(in[i][j]=='*')
                arr[i][j]=1;
            else
                arr[i][j]=0;

    resetVisited();
    locateOcean();
    resetVisited();
    locateLake();
    output();
    return 0;
}
