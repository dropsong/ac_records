#include<bits/stdc++.h>
using namespace std;
int a[105];
int b[105];
int nb(int i,int x)
{
    int sum=0;
    for(int j=1;j<=i;j++)
    {
        if(a[j]<x)sum++;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=nb(i,a[i]);
    }
    for(int i=1;i<=n;i++)
    cout<<b[i]<<" ";
    return 0;
}