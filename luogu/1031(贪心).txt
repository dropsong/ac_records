#include<bits/stdc++.h>
using namespace std;
int a[105];
int sum,total;
void work(int i,int j)
{
    if(i==j)return;
    while(a[i]==0)i++;
    a[i+1]+=a[i];
    total++;
    a[i]=0;
    work(i+1,j);
}
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    sum=sum/n;
    for(int i=1;i<=n;i++) a[i]=a[i]-sum;
    int i=1,j=n;
    while(a[i]==0)
    {
        i++;
        if(i==j+1)
        {
            cout<<"0";
            return 0;
        }
    }
    while(a[j]==0)j--;
    work(i,j);
    cout<<total;
    return 0;
}