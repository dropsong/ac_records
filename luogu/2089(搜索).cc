#include<bits/stdc++.h>
using namespace std;
int n,ans;
int b[30000][11];
int a[11];
void print()
{
    for(int jjj=1;jjj<=ans;jjj++)
    {
        for(int iii=1;iii<=10;iii++)
        {
            cout<<b[jjj][iii]<<" ";
        }
        cout<<endl;
    }
}
void search(int x,int sum)
{
    if(x==11)
    {
        if(sum==n)
        {
            ans++;
            for(int t=1;t<=10;t++)
            {
                b[ans][t]=a[t];
            }
        }
        return;
    }
    else 
    {
        for(int i=1;i<=3;i++)
        {
            a[x]=i;
            search(x+1,sum+i);
            a[x]=0;
        }
    }
}
int main()
{
    cin>>n;
    if(n>30)
    {
        cout<<0;
        return 0;
    }
    else search(1,0);
    cout<<ans<<endl;
    print();
    return 0;
}