#include<bits/stdc++.h>
using namespace std;

class node
{
public:
    int n;
    char arr[21];
    node(char b[],int a)
    {
        n=a;
        strcpy(arr,b);
    }
};

int main()
{
    long int i,n,m;
    cin>>n>>m;
    vector< vector< node > > vec;
    bool vis[m][3];
    for(i=0;i<m;i++)
        vis[i][0]=vis[i][1]=vis[i][2]=0;
    vec.resize(m);
    char a[21];
    int r,sc;
    for(i=0;i<n;i++)
    {
        cin>>a>>r>>sc;
        if(!vis[r-1][0])
        {
            vec[r-1].push_back(node(a,sc));
            vis[r-1][0]=1;
        }
        else if(!vis[r-1][1])
        {
            vec[r-1].push_back(node(a,sc));
            vis[r-1][1]=1;
            if(vec[r-1][1].n>vec[r-1][0].n)
                swap(vec[r-1][0],vec[r-1][1]);
        }
        else if(!vis[r-1][2])
        {
            vec[r-1].push_back(node(a,sc));
            vis[r-1][2]=1;
            if(vec[r-1][2].n>vec[r-1][0].n)
            {
                swap(vec[r-1][0],vec[r-1][1]);
                swap(vec[r-1][0],vec[r-1][2]);
            }
            else if(vec[r-1][2].n>vec[r-1][1].n)
                swap(vec[r-1][1],vec[r-1][2]);
        }
        else
        {
            if(sc>vec[r-1][0].n)
            {
                swap(vec[r-1][0],vec[r-1][1]);
                swap(vec[r-1][0],vec[r-1][2]);
                vec[r-1][0].n=sc;
                strcpy(vec[r-1][0].arr,a);
            }
            else if(sc>vec[r-1][1].n)
            {
                swap(vec[r-1][1],vec[r-1][2]);
                vec[r-1][1].n=sc;
                strcpy(vec[r-1][1].arr,a);
            }
            else if(sc>vec[r-1][2].n)
            {
                vec[r-1][2].n=sc;
                strcpy(vec[r-1][2].arr,a);
            }
        }
    }
    for(i=0;i<m;i++)
    {
        if(vis[i][2])
        {
            if(vec[i][1].n==vec[i][2].n)
                cout<<"?\n";
            else
                cout<<vec[i][0].arr<<" "<<vec[i][1].arr<<endl;

        }
        else
            cout<<vec[i][0].arr<<" "<<vec[i][1].arr<<endl;
    }
    return 0;
}
