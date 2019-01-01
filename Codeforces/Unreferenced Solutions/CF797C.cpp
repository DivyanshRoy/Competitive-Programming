#include<bits/stdc++.h>
using namespace std;

int main()
{
    char arr[100005],str[100005];
    long int sf[100005],c;
    long int la,ls,i;
    cin>>arr;
    la=strlen(arr);
    c=la-1;
    for(i=la-1;i>=0;i--)
    {
        if(arr[i]<=arr[c])
        {
            sf[i]=i;
            c=i;
        }
        else
            sf[i]=c;
    }
    stack<char> st;
    ls=0;
    for(i=0;i<la;i++)
    {
        while(!st.empty()&&st.top()<=arr[sf[i]])
        {
            str[ls++]=st.top();
            st.pop();
        }
        while(sf[i]!=i)
        {
            st.push(arr[i]);
            i++;
        }
        str[ls++]=arr[i];
    }
    while(!st.empty())
    {
        str[ls++]=st.top();
        st.pop();
    }
    for(i=0;i<ls;i++)
        cout<<str[i];
    return 0;
}
