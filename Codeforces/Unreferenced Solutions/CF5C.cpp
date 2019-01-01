#include<bits/stdc++.h>
using namespace std;

int main()
{
    char arr[1000001];
    long int len,i,j,mx=0,val,cm=1,o,c;
    cin>>arr;
    len=strlen(arr);
    for(i=0;i<len;i++)
    {
        o=c=val=0;
        for(j=i;j<len;j++)
        {
            if(arr[j]=='(')
                o++;
            else
                o--;
            if(o<0)
            {
                i=j;
                break;
            }
            else
            {
                val++;
            }
            if(o==0)
            {
                if(val>mx)
                {
                    mx=val;
                    cm=1;
                }
                else if(mx==val)
                    cm++;
            }

        }
    }
    cout<<mx<<" "<<cm;
    return 0;
}
