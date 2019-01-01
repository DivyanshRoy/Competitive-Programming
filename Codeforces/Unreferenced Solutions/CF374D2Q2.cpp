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

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
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
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int calc(int num,int k)
{
    int t=num;
    t+=((num/k)*5);
    return t;
}

int main()
{
    int n,k,i;
    cin>>n>>k;
    char arr[101];
    char arrst[n][101];
    int l[n];
    set<int> s;
    for(i=0;i<n;i++)
    {
        cin>>arr;
        strcpy(arrst[i],arr);
        l[i]=strlen(arr);
        s.insert(l[i]);
    }
    cin>>arr;
    int cnt=0;
    for(i=0;i<n;i++)
        if(strcmp(arrst[i],arr)==0)
            cnt++;
    int mx=0,mn=0,len=strlen(arr),st=0;
    if(cnt==0)
    {
        mn=mx=1+calc(n-1,k);
        return 0;
    }
    radixsort(l,n);
    for(i=0;i<n;i++)
    {
        if(l[i]==len)
        {
            mn=1+(calc(st,k));
            int j;
            for(j=i;j<n&&l[j]==len;j++)
            {
                st++;
            }
            mx=1+(calc(st-cnt,k));
            break;
        }
        else
        {
            st++;
        }
    }
    cout<<mn<<" "<<mx;
    return 0;
}
