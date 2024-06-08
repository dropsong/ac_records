#include<cstdio>
#include<queue>
#define MAXN 105
#define MAXM 5005
#define INF 0x7fffffff
using namespace std;

int n,len,m,fa[MAXN],inq[MAXN],dis[MAXN];
int temp,tot,head[MAXN],info[MAXN][MAXN];
struct Edge{
    int v,w,next;
}edge[MAXM<<1];

inline void addedge(int x,int y,int z)
{
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

bool ok=true;
void spfa(int s)
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    queue<int> qwq; qwq.push(s);
    inq[s]=true; dis[s]=0;
    
    while(!qwq.empty())
    {
        int x=qwq.front();
        qwq.pop(); inq[x]=false;
        for(int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].v;
            if(dis[y]>dis[x]+edge[i].w)
            {
                dis[y]=dis[x]+edge[i].w;
                if(ok)fa[y]=x;
                if(ok)info[x][y]=i,info[y][x]=i^1;
                if(!inq[y]){
                    qwq.push(y);
                    inq[y]=true;
                }
            }
        }
    }
}

void dfs(int x)
{
    if(!fa[x])return;
    int num=info[fa[x]][x];
    edge[num].w<<=1;
    edge[num^1].w<<1;
    for(int i=1;i<=n;i++)dis[i]=0;
    spfa(1);
    temp=max(temp,dis[n]);
    edge[num].w>>=1;
    edge[num^1].w>>=1;
    dfs(fa[x]);
}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    
    spfa(1); len=dis[n]; ok=false;
    
    dfs(n); printf("%d",temp-len);
    return 0;
}
