#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int calc(char arr[])
{
    int i,len=strlen(arr),cnt=0;
    bool b[26];
    for(i=0;i<26;i++)
        b[i]=0;
    for(i=0;i<len;i++)
    {
        if(arr[i]>='A'&&arr[i]<='Z')
        {
            b[arr[i]-'A']=1;
        }
    }
    for(i=0;i<26;i++)
    {
        if(b[i])
            cnt++;
    }
    return cnt;
}

int main()
{
    freopen("A-small-attempt4.in","r",stdin);
    freopen("outputA.txt","w",stdout);
    int t,n,i,j,mx=0,tmp;
    //map<int, vector<string> > ma;
    //vector<string>::iterator iter;
    char arr[21];
    //string arr;
    char store[100][21];
    int score[100];
    char least[21];
    bool b;
    cin>>t;
    j=1;
    while(j<=t)
    {
        cin>>n;
//        ma.clear();
        mx=0;
        for(i=0;i<n;i++)
        {
            cin>>arr;
            strcpy(store[i],arr);
            //string str(arr);
            tmp=calc(arr);
            score[i]=tmp;
            //ma[tmp].push_back(str);
            mx=max(mx,tmp);
        }
        b=1;
        for(i=0;i<n;i++)
        {
            if(score[i]==mx)
            {
                if(b)
                {
                    b=0;
                    strcpy(least,store[i]);
                }
                else
                {
                    if(strcmp(store[i],least)<0)
                    {
                        strcpy(least,store[i]);
                    }
                }
            }
        }
        //iter=ma[mx].begin();
        cout<<"Case #"<<j<<": "<<least<<endl;
        j++;
    }
    return 0;
}
