//水题进行时。。。 
#include<cstdio>
#define MAXN 1005

int n,m,total,s,rep;
int a[MAXN][MAXN];
int dir[4][2]={{-1,0},{0,1},{1,0},{0,-1}};
void prework(){s=6*total;s-=rep;rep=0;}

inline bool clear()
{
    bool ok=false;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        if(a[i][j])a[i][j]--;
        if(a[i][j])ok=true;
    }
    return ok;
}
inline bool judge(int x,int y)
{
    if(x<1||x>n)return true;
    if(y<1||y>m)return true;
    return false;
}

void input();
int search();
int main()
{
    input();
    prework();
    //一层一层地处理 
    do
    {
        rep=0;
        s-=search();
    } while(clear());
    //如果仍然有方块就继续执行 
    printf("%d",s);
    return 0;
}

void input()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        scanf("%1d",&a[i][j]);
        total+=a[i][j];
        if(a[i][j])rep+=2*(a[i][j]-1);
    }
}

inline int search()
{
    for(int x=1;x<=n;x++)
    for(int y=1;y<=m;y++)
    {
        if(a[x][y])
        for(int direc=0;direc<=3;direc++)
        {
            int nx=x+dir[direc][0];
            int ny=y+dir[direc][1];
            if(judge(nx,ny))continue;
            if(a[nx][ny])rep++;
        }
    }
    return rep;
}