//苟非吾之所有，虽1 s而莫取。
#include<bits/stdc++.h>
#define INF 0x7fffffff
#define MAXN 1050
using namespace std;

bool vis[MAXN][MAXN];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
int onfire[MAXN][MAXN];
int n,m,t,sx,sy;
char a[MAXN][MAXN];
struct node{int x,y,time;};
queue<node> qwq;

void initbfs()
{
    while(!qwq.empty())
    {
        node u=qwq.front(); qwq.pop();
        for(int i=0;i<4;i++)
        {
            int nx=u.x+dx[i],ny=u.y+dy[i];
            if(!(nx>=1&&nx<=n&&ny>=1&&ny<=m))continue;
            if(a[nx][ny]!='#'&&onfire[nx][ny]==INF)
            {
                qwq.push(node{nx,ny,0});
                onfire[nx][ny]=onfire[u.x][u.y]+1;
            }
        }
    } 
}

void bfs()
{
    while(!qwq.empty())qwq.pop();
    qwq.push(node{sx,sy,0});
    vis[sx][sy]=true;
    
    while(!qwq.empty())
    {
        node u=qwq.front(); qwq.pop();
        if(u.x==n||u.x==1||u.y==1||u.y==m)
        {
            printf("%d\n",u.time+1);
            return;
        }
        for(int i=0;i<4;i++)
        {
            int nx=u.x+dx[i],ny=u.y+dy[i];
            if(!(nx>=1&&nx<=n&&ny>=1&&ny<=m))continue;
            if(!(a[nx][ny]!='#'&&!vis[nx][ny]))continue;
            if(u.time+1<onfire[nx][ny]){
                qwq.push(node{nx,ny,u.time+1});
                vis[nx][ny]=true;
            }
        }
    }
    
    printf("IMPOSSIBLE\n");
    return;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d",&t);
    while(t--)
    {
        while(!qwq.empty())qwq.pop();
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            vis[i][j]=false;
            onfire[i][j]=INF;
        }
        for(int i=1;i<=n;i++)
        scanf("%s",a[i]+1);
        
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]=='J')sx=i,sy=j;
            if(a[i][j]=='F')
            {
                qwq.push(node{i,j,0});
                onfire[i][j]=0;
            }
        }
        initbfs(); bfs();
    }
    
    return 0;
}
