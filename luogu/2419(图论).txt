#include<bits/stdc++.h>
#define maxn 110
using namespace std;

int n,m,ans;
bool matrix[maxn][maxn];
bool ok[maxn];

inline void floyd()
{
    for(int k=1;k<=n;k++)
     for(int u=1;u<=n;u++)
      for(int v=1;v<=n;v++)
       if(matrix[u][k] && matrix[k][v])
       matrix[u][v]=true;
}

int main()
{
    memset(ok,true,sizeof(ok));
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int a,b;
        cin>>a>>b;
        matrix[a][b]=true;
    }
    
    floyd();
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i==j)continue;
        if((!matrix[i][j])&&(!matrix[j][i]))ok[i]=false;
    }
    for(int i=1;i<=n;i++)
    if(ok[i])ans++;
    
    cout<<ans;
    return 0;
}