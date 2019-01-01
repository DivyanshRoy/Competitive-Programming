#include<bits/stdc++.h>
using namespace std;

int getMax(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

void countSort(int arr[],int arr1[], int n, int exp)
{
    int output[n],o[n];
    int i, count[10] = {0};
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

void radixsort(int arr[],int arr1[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr,arr1, n, exp);
}

int main()
{
    int n,m,k,i,j;
    cin>>n>>m>>k;
    char arr[n][m],arr1[n][m];
    for(i=0;i<n;i++)
        cin>>arr[i];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            arr1[i][j]=arr[i][j];
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(arr[i][j]=='.')
            {
                if(i==0||i==n-1||j==0||j==m-1)
                    arr[i][j]='A';
                else if(arr[i-1][j]=='A'&&i>0)
                    arr[i][j]='A';
                else if(arr[i+1][j]=='A'&&i<n-1)
                    arr[i][j]='A';
                else if(arr[i][j-1]=='A'&&j>0)
                    arr[i][j]='A';
                else if(arr[i][j+1]=='A'&&j<m-1)
                    arr[i][j]='A';
            }
        }
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
        {
            if(arr[i][j]=='.')
            {
                if(i==0||i==n-1||j==0||j==m-1)
                    arr[i][j]='A';
                else if(arr[i-1][j]=='A'&&i>0)
                    arr[i][j]='A';
                else if(arr[i+1][j]=='A'&&i<n-1)
                    arr[i][j]='A';
                else if(arr[i][j-1]=='A'&&j>0)
                    arr[i][j]='A';
                else if(arr[i][j+1]=='A'&&j<m-1)
                    arr[i][j]='A';
            }
        }
    int cnt=70,flag=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            flag=0;
            if(arr[i][j]=='.')
            {
                if(arr[i-1][j]>69)
                {
                    arr[i][j]=arr[i-1][j];
                    flag=1;
                }
                if(arr[i+1][j]>69)
                {
                    arr[i][j]=arr[i+1][j];
                    flag=1;
                }
                if(arr[i][j-1]>69)
                {
                    arr[i][j]=arr[i][j-1];
                    flag=1;
                }
                if(arr[i][j+1]>69)
                {
                    arr[i][j]=arr[i][j+1];
                    flag=1;
                }
                if(!flag)
                    arr[i][j]=cnt++;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            flag=0;
            if(arr[i][j]=='.')
            {
                if(arr[i-1][j]>69&&i>0)
                {
                    arr[i][j]=arr[i-1][j];
                    flag=1;
                }
                if(arr[i+1][j]>69&&i<n-1)
                {
                    arr[i][j]=arr[i+1][j];
                    flag=1;
                }
                if(arr[i][j-1]>69&&j>0)
                {
                    arr[i][j]=arr[i][j-1];
                    flag=1;
                }
                if(arr[i][j+1]>69&&j<m-1)
                {
                    arr[i][j]=arr[i][j+1];
                    flag=1;
                }
                if(arr[i-1][j-1]>69&&i>0&&j>0)
                {
                    arr[i][j]=arr[i-1][j-1];
                    flag=1;
                }
                if(arr[i+1][j-1]>69&&i<n-1&&j>0)
                {
                    arr[i][j]=arr[i+1][j-1];
                    flag=1;
                }
                if(arr[i-1][j+1]>69&&i>0&&j<m-1)
                {
                    arr[i][j]=arr[i-1][j+1];
                    flag=1;
                }
                if(arr[i+1][j+1]>69&&i<n-1&&j<m-1)
                {
                    arr[i][j]=arr[i+1][j+1];
                    flag=1;
                }
                if(!flag)
                    arr[i][j]=cnt++;
            }
        }
    }

    int num=cnt-70;
    if(k==num)
    {
        cout<<0<<endl;
        for(i=0;i<n;i++)
        {
            for(j=0;j<m;j++)
                cout<<arr1[i][j];
            cout<<endl;
        }
        return 0;
    }
    int lc[num],loclc[num];
    for(i=0;i<num;i++)
    {
        lc[i]=0;
        loclc[i]=i;
    }
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            lc[arr[i][j]-70]++;
    radixsort(lc,loclc,num);
    int deleted=0;
    set<int> s;
    for(i=0;i<num-k;i++)
    {
        deleted+=lc[i];
        s.insert(loclc[i]);
    }
    cout<<deleted<<endl;
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        {
            if(arr[i][j]>69)
            {
                if(s.find(arr[i][j]-70)!=s.end())
                    cout<<"*";
                else
                    cout<<".";
            }
            else if(arr[i][j]=='A')
                cout<<".";
            else
                cout<<arr[i][j];
        }
        cout<<endl;
    }
    return 0;
}
