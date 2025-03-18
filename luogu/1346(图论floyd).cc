#include<cstdio>
#include<climits>
#include<algorithm>
using namespace std;

const int MAXN =100+5;
bool matrix[MAXN][MAXN];
int dis[MAXN][MAXN],n,s,e;
int to[MAXN];

inline void init()
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        if(i==j)dis[i][j]=0;
        else dis[i][j]=INT_MAX>>1;
    }
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    if(matrix[i][j])
    {
        if(to[i]==j)dis[i][j]=0;
        else dis[i][j]=1;
    }
}

int main()
{
    scanf("%d%d%d",&n,&s,&e);
    for(int i=1;i<=n;i++)
    {
        int sum,temp;
        scanf("%d",&sum);
        bool ok=true;
        for(int j=1;j<=sum;j++)
        {
            scanf("%d",&temp);
            if(temp==i)continue;
            if(ok)to[i]=temp,ok=false;
            matrix[i][temp]=true;
        }
    }
    
    init();
    
    for(int k=1;k<=n;k++)
     for(int i=1;i<=n;i++)
      for(int j=1;j<=n;j++)
       dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
        
    if(dis[s][e]==(INT_MAX>>1))
    {
        printf("-1");return 0;
    }
    printf("%d",dis[s][e]);
    return 0;
}
