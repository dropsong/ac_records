//每一个不曾AC的日子都是一种遗憾 
#include<bits/stdc++.h>
#define MAXN 105
using namespace std;

int m,n,ans=0x3fffffff;
int color[MAXN][MAXN];
int cost[MAXN][MAXN];
const int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};

void dfs(int x,int y,int sum,bool mogicok)
{
    if(x<1||y<1||x>m||y>m)return ;
    if(sum>=cost[x][y])return ;
    if(!color[x][y])return ;
    cost[x][y]=sum;
    if(x==m&&y==m){
        if(sum<ans)ans=sum;
        return ;
    }
    
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        
        if(color[nx][ny]){
            if(color[x][y]==color[nx][ny])dfs(nx,ny,sum,true);
            else dfs(nx,ny,sum+1,true); 
        }
        else if(!color[nx][ny]&&mogicok){
            color[nx][ny]=color[x][y];
            dfs(nx,ny,sum+2,false);
            color[nx][ny]=0;
        }
    }
}

int main()
{
    memset(cost,0x7f,sizeof(cost));
    
    cin>>m>>n;
    int x,y,c;
    for(int i=1;i<=n;i++)
    {
        cin>>x>>y>>c;
        color[x][y]=c+1;
    }
    
    dfs(1,1,0,true);
    
    if(ans==0x3fffffff)cout<<-1;
    else cout<<ans;
    return 0;
}