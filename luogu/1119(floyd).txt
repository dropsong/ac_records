#include<bits/stdc++.h>
#define MAXN 210
#define MAXM 50010
using namespace std;

int n,m,q,k;
int dis[MAXN][MAXN],t[MAXM];

void input()
{
    scanf("%d%d",&n,&m);
    memset(dis,0x3f,sizeof(dis));
    memset(t,0x3f,sizeof(t));
    for(int i=0;i<n;i++)
    scanf("%d",&t[i]),dis[i][i]=0;
    
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        dis[x][y]=dis[y][x]=z;
    }
    scanf("%d",&q);
}

int main()
{
    input();
    int x,y,z;
    while(q--)
    {
        scanf("%d%d%d",&x,&y,&z);
        while(t[k]<=z)
        {
            for(int i=0;i<n;i++)
             for(int j=0;j<n;j++)
              if(dis[i][j]>dis[i][k]+dis[k][j])
              dis[i][j]=dis[i][k]+dis[k][j];
            k++;
        }
        if(dis[x][y]==0x3f3f3f3f||t[x]>z||t[y]>z)printf("-1\n");
        else printf("%d\n",dis[x][y]);
    }
    return 0;
}
