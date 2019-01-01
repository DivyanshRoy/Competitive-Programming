#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n,k,i,j;
    cin>>n>>k;
    long int arr[n];
    for(i=0;i<n;i++)
        arr[i]=i+1;
    if(k%2==0)
    {
        for(i=0,j=k-1;i<=j;i+2,j-=2)
        {
            swap(arr[i],arr[j]);
        }
    }
    else
    {
        for(i=0,j=k-1;i<=j;i+2,j-=2)
        {
            swap(arr[i],arr[j]);
        }
        //swap(arr[i-1],arr[j+1]);
    }
    for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
    return 0;
}


