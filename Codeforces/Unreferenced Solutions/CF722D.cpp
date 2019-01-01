#include<bits/stdc++.h>
using namespace std;

long int getMax(long int arr[], long int n)
{
    long int mx = arr[0];
    for (long int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(long int arr[], long int n, long int exp)
{
    long int output[n];
    long int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[n-i-1] = output[i];
}

void radixsort(long int arr[], long int n)
{
    long int m = getMax(arr, n);
    for (long int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main()
{
    int N,i;
    cin>>N;
    long int arr[N],e;
    set<long int> s;
    vector<long int> vec;
    for(i=0;i<N;i++)
    {
        scanf("%ld",&arr[i]);
        s.insert(arr[i]);
    }
    sort(arr,arr+N);
    for(i=0;i<N/2;i++)
        swap(arr[i],arr[N-i-1]);
    for(i=0;i<N;i++)
    {
        e=arr[i];
        cout<<arr[i]<<" ";
        s.erase(e);
        while(s.find(e/2)==s.end()&&(e/2)>0)
        {
            e/=2;
        }
        s.insert(e);
        vec.push_back(e);
    }
    cout<<endl;
    vector<long int>::iterator iter;
    for(iter=vec.begin();iter!=vec.end();iter++)
        cout<<*iter<<" ";
    return 0;
}
