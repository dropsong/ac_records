#include<cstdio>
#include<queue>
#define MAXN 1510
#define MAXM 50010
#define INF 0x7fffffff
using namespace std;

int tot,head[MAXN];
int dis[MAXN],n,m;
bool inq[MAXN];

struct Edge{
    int v,w,next;
}edge[MAXM];

inline void addedge(int x,int y,int z)
{
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

void spfa()
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    queue<int> qwq; dis[1]=0;
    qwq.push(1); inq[1]=true;
    
    while(!qwq.empty())
    {
        int x=qwq.front();
        qwq.pop();inq[x]=false;
        for(int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].v;
            if(dis[y]>dis[x]+edge[i].w)
            {
                dis[y]=dis[x]+edge[i].w;
                if(!inq[y]){qwq.push(y);inq[y]=true;}
            }
        }
    }
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,-z);
    }
    
    spfa();
    
    if(dis[n]==INF){printf("-1");return 0;}
    printf("%d",-dis[n]);
    return 0;
}
