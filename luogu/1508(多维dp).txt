#include<bits/stdc++.h>
#define MAXN 205
#define INF 1199999999
using namespace std;

int m,n;
int f[MAXN][MAXN],w[MAXN][MAXN];

int dp(int x,int y)
{
    if(f[x][y]!=(-INF))return f[x][y];
    if(x==1) return w[x][y];
    if(y<1||y>n)return (-INF);
    
    f[x][y]=max(max(dp(x-1,y),dp(x-1,y-1)),dp(x-1,y+1))+w[x][y];
    
    return f[x][y];
}

int main()
{
    for(int i=0;i<MAXN;i++)
    for(int j=0;j<MAXN;j++)
    f[i][j]=-INF;
    
    cin>>m>>n;
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++)
    scanf("%d",&w[i][j]);
    
    cout<<dp(m+1,n/2+1);
    return 0;
}