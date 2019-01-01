// Problem Link: https://www.codechef.com/AUG17/problems/PALINGAM

#include<bits/stdc++.h>
using namespace std;

#define maxn 1005
int T;
char s[maxn],t[maxn];
int cnta[26],cntb[26];
int main(){
    cin>>T;
    for (;T--;){
        scanf("%s%s",s,t);
        int len=strlen(s);
        memset(cnta,0,sizeof(cnta));
        memset(cntb,0,sizeof(cntb));
        for (int i=0;i<len;i++){
            int a=s[i]-'a',b=t[i]-'a';
            cnta[a]++,cntb[b]++;
        }
        int uniqueA=0,uniqueB=0;
        for (int i=0;i<26;i++){
            if (cnta[i]==0 && cntb[i]){
                uniqueB=max(uniqueB,cntb[i]);
            }
            if (cnta[i] && cntb[i]==0){
                uniqueA=max(uniqueA,cnta[i]);
            }
        }
        if (uniqueA==0){
            puts("B");
        }
        else if (uniqueA>=2){
            puts("A");
        }
        else{
            if (uniqueB==0){
                puts("A");
            }
            else puts("B");
        }
    }
    return 0;
}