//暴力碾标算orz，比题解里的floyd快。
#include<bits/stdc++.h>
#define INF 0x7fffffff
#define MAXN 105
using namespace std;

int dep[MAXN],val[MAXN];
int ans=INF,n;
bool vis[MAXN];
bool _map[MAXN][MAXN];

int dfs(int x)
{
    vis[x]=true;
    for(int i=1;i<=n;i++)
    {
        if(!_map[x][i])continue;
        if(vis[i])continue;
        vis[i]=true;
        dep[i]=dep[x]+1;
        dfs(i);
    }
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        val[i]=x;
        if(y)_map[i][y]=_map[y][i]=true;
        if(z)_map[i][z]=_map[z][i]=true;
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)    //init
        vis[j]=false,dep[j]=0;
        dfs(i); int temp=0;
        for(int j=1;j<=n;j++)
        temp+=(dep[j]*val[j]);
        if(temp<ans)ans=temp;
    }
    
    printf("%d",ans);
    return 0;
}
