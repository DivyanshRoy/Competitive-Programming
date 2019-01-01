#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,i;
    cin>>n;
    char arr[n];
    cin>>arr;
    vector<int> vec;
    for(i=0;i<n;i++)
    {
        if(arr[i]=='2')
        {
            vec.push_back(2);
        }
        else if(arr[i]=='3')
        {
            vec.push_back(3);
        }
        else if(arr[i]=='4')
        {
            vec.push_back(3);
            vec.push_back(2);
            vec.push_back(2);
        }
        else if(arr[i]=='5')
        {
            vec.push_back(5);
        }
        else if(arr[i]=='6')
        {
            vec.push_back(5);
            vec.push_back(3);
        }
        else if(arr[i]=='7')
        {
            vec.push_back(7);
        }
        else if(arr[i]=='8')
        {
            vec.push_back(7);
            vec.push_back(2);
            vec.push_back(2);
            vec.push_back(2);
        }
        else if(arr[i]=='9')
        {
            vec.push_back(7);
            vec.push_back(3);
            vec.push_back(3);
            vec.push_back(2);
        }
    }
    sort(vec.begin(),vec.end());
    vector<int>::reverse_iterator iter;
    for(iter=vec.rbegin();iter!=vec.rend();iter++)
        cout<<*iter;
    return 0;
}
