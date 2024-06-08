#include<bits/stdc++.h>
#define MAXN 35
using namespace std;

int n,v[MAXN];
int f[MAXN][MAXN],p[MAXN][MAXN];

int dp(int l,int r)
{
    if(l>r)return 1;
    if(f[l][r]!=-1)return f[l][r];
    if(l==r){p[l][r]=l;return v[l];}
    
    int &ans=f[l][r],&pos=p[l][r];
    for(int i=l;i<=r;i++)
    if(dp(l,i-1)*dp(i+1,r)+v[i]>ans)
    ans=dp(l,i-1)*dp(i+1,r)+v[i],pos=i;
    return ans;
}

void output(int l,int r)
{
    int pos=p[l][r];
    printf("%d ",pos);
    if(l<=pos-1)output(l,pos-1);
    if(r>=pos+1)output(pos+1,r);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    scanf("%d",&v[i]);
    memset(f,-1,sizeof(f));
    printf("%d\n",dp(1,n));
    output(1,n);
    return 0;
}