#include<stdio.h>
#define MAXN 405
#define HOME
using namespace std;

int front,rear;
int n,m,x0,y0;
int q[MAXN*MAXN][2];
int a[MAXN][MAXN];
bool vis[MAXN][MAXN];
int dir[8][2]={{-2,1},{-1,2},{1,2},{2,1},
               {2,-1},{1,-2},{-1,-2},{-2,-1}};

inline bool judge(int nx,int ny)
{
    if(nx>n||ny>m)return false;
    if(nx<1||ny<1)return false;
    if(vis[nx][ny])return false;
    return true;
}

void BFS()
{
    while(front<=rear)
    {
        for(int i=0;i<=7;i++)
        {
            int x=q[front][0];
            int y=q[front][1];
            int nx,ny;
            nx=x+dir[i][0]; ny=y+dir[i][1];
            if(judge(nx,ny))
            {
                rear++;
                q[rear][0]=nx; q[rear][1]=ny;
                a[nx][ny]=a[x][y]+1;
                vis[nx][ny]=true;
            }
        }
        front++;
    }
}

void output()
{
     for(int i=1;i<=n;i++)
     {
        for (int j=1;j<=m;j++)
        {
        	if(!vis[i][j])a[i][j]=-1;
        	printf("%-5d",a[i][j]);
        }
        printf("\n");
     }
}

int main()
{
#ifdef NOIP
    freopen(".in","r",stdio);
    freopen(".out","w",stdout);
#endif
    
    scanf("%d%d%d%d",&n,&m,&x0,&y0);
    
    front=rear=1;
    q[front][0]=x0; q[front][1]=y0;
    vis[x0][y0]=true; 
    a[x0][y0]=0;
    
    BFS();
    
    output();
    
    return 0;
}