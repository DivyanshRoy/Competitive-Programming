#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i,cnt=0;
    vector<int> v;
    bool b=0;
    cin>>n;
    char arr[n];
    cin>>arr;
    for(i=0;i<n;i++)
        if(arr[i]=='B')
            if(!b)
            {
                b=1;
                cnt++;
                v.push_back(1);
            }
            else
                v[v.size()-1]++;
        else
            b=0;
    cout<<cnt<<endl;
    for(i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    return 0;
}
