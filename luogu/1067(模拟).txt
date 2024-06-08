#include<bits/stdc++.h>
using namespace std;
int a[105];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n+1;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        if(a[i]==0)
        {if(a[i+1]>0)cout<<"+";continue;}
        
        if(a[i]==1)cout<<"x";
        else if(a[i]==-1)cout<<"-x";
        else cout<<a[i]<<"x";
        
        
        if(n-i+1!=1)cout<<"^"<<n-i+1;
         //if(a[i+1]<0)cout<<"-";
         if(a[i+1]>0)cout<<"+";
    }
    if(a[n+1]>0)
    {
        cout<<a[n+1];
        return 0;
    }
    if(a[n+1]==0)return 0;
    cout<<a[n+1];
    return 0;
}