#include<bits/stdc++.h>
#define MAXN 405
using namespace std;

int n,ans;
int f[MAXN][MAXN];
int a[MAXN<<1];

int dp(int l,int r)
{
    if(f[l][r])return f[l][r];
    if(l==r-1)return f[l][r]=a[l]*a[r]*a[r+1];
    for(int k=l;k<r;k++)
    f[l][r]=max(f[l][r],dp(l,k)+dp(k+1,r)+a[l]*a[k+1]*a[r+1]);
    return f[l][r];
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i+n]=a[i];
    }
    a[n*2+1]=a[1];
    for(int i=1;i<=n;i++)
    ans=max(ans,dp(i,n+i-1));
    cout<<ans;
    return 0;
}
