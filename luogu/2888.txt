#include<iostream>
#include<cstdio>
#include<cstring>
#define inf 1000000000
using namespace std;
int n,m,p,d[301][301];
int main()
{
    memset(d,0x3f,sizeof(d));
    scanf("%d%d%d",&n,&m,&p);
    for(int i=1;i<=m;i++)
    {
        int u,v,w;scanf("%d%d%d",&u,&v,&w);
        d[u][v]=min(d[u][v],w);
    }
    for(int k=1;k<=n;k++)
       for(int i=1;i<=n;i++)
          for(int j=1;j<=n;j++)
             d[i][j]=min(max(d[i][k],d[k][j]),d[i][j]);
    for(int i=1;i<=p;i++)
    {
        int x,y;scanf("%d%d",&x,&y);
        if(d[x][y]<inf)printf("%d\n",d[x][y]);
        else printf("-1\n");
    }
    return 0;
}
