#include<cstdio>
const int MAXN=1003;
int n,m,kkk;
int a[MAXN][MAXN];
int result[MAXN][MAXN];
int coordinate[MAXN*MAXN][2];
int dir[4][2]={-1,0,1,0,0,-1,0,1};

void dfs(int i,int j)
{
    kkk++;
    coordinate[kkk][0]=i;
    coordinate[kkk][1]=j;
    result[i][j]=1;
    
    for(int laji=0;laji<=3;laji++)
    {
        int nx=i+dir[laji][0];
        int ny=j+dir[laji][1];
        if(nx>=1&&nx<=n&&ny>=1&&ny<=n)
        if(result[nx][ny]==0&&(a[i][j]!=a[nx][ny]))
            dfs(nx,ny);
    }
}

inline void input()
{
    scanf("%d%d",&n,&m);
    for(int k=1;k<=n;k++)
    for(int o=1;o<=n;o++)
        scanf("%1d",&a[k][o]);
        
    for(int k=1;k<=m;k++)
    {
        kkk=0;
        int i,j;
        scanf("%d%d",&i,&j);
        
        if(result[i][j]!=0)
        {
            printf("%d\n",result[i][j]);
            continue;
        }
        
        dfs(i,j);
        for(int lintoto=1;lintoto<=kkk;lintoto++)
        {
            result[coordinate[lintoto][0]][coordinate[lintoto][1]]=kkk;
        }
        printf("%d\n",kkk);
    }
}

int main()
{
    input();	
    return 0;
}