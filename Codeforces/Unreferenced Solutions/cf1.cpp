#include<iostream>
using namespace std;

int main()
{
    int T,i,flag=0;
    cin>>T;
    char arr[T][5];
    for(i=0;i<T;i++)
        cin>>arr[i];
    for(i=0;i<T;i++)
    {
        if(arr[i][0]=='O'&&arr[i][1]=='O')
        {
            arr[i][0]=arr[i][1]='+';
            flag=1;
            break;
        }
        else if(arr[i][3]=='O'&&arr[i][4]=='O')
        {
            arr[i][3]=arr[i][4]='+';
            flag=1;
            break;
        }
    }
    if(flag)
    {
        cout<<"YES\n";
        for(i=0;i<T;i++)
            cout<<arr[i][0]<<arr[i][1]<<arr[i][2]<<arr[i][3]<<arr[i][4]<<endl;
    }
    else
        cout<<"NO";

    return 0;
}
