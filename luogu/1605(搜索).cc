#include<bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,fx,fy;
int ans;
int dir[4][2]={-1,0,0,1,1,0,0,-1};
bool migong[8][8];
void input()
{
    scanf("%d%d%d",&n,&m,&t);
    scanf("%d%d%d%d",&sx,&sy,&fx,&fy);
    migong[sx][sy]=true;
    for(int i=1;i<=t;i++)
    {
        int tempx,tempy;
        scanf("%d%d",&tempx,&tempy);
        migong[tempx][tempy]=true;
    }
}

void dfs(int x,int y)
{
    if(x==fx&&y==fy)
    {
        ans++;
        return;
    }
    for(int j=0;j<4;j++)
    {
        int nx,ny;
        nx=x+dir[j][0];
        ny=y+dir[j][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=m&&(!migong[nx][ny]))
        {
            migong[nx][ny]=true;
            dfs(nx,ny);
            migong[nx][ny]=false;
        }
    }
}
int main()
{
    input();
    dfs(sx,sy);
    printf("%d",ans);
    return 0;
}