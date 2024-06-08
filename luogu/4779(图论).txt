#include<bits/stdc++.h>
#define MAXM 200010
#define MAXN 100010
using namespace std;

struct Edge{
    int v,w;
    int next;
}edge[MAXM];
int tot,head[MAXN];
int n,m,s;
int dis[MAXN];

void addedge(int x,int y,int z)
{
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

struct node{
    int u,d;
    bool operator <(const node& v)const
    {
        return d>v.d;
    }
};

inline void dijkstra()
{
    for(int i=1;i<=n;i++)dis[i]=2147483647;
    dis[s]=0;
    priority_queue<node> qwq;
    qwq.push((node){s,0});
    
    while(!qwq.empty())
    {
        node fr=qwq.top(); qwq.pop();
        int u=fr.u,d=fr.d;
        if(d!=dis[u])continue;
        for(int i=head[u];i;i=edge[i].next)
        {
            int v=edge[i].v,w=edge[i].w;
            if(dis[u]+w<dis[v])
            {
                dis[v]=dis[u]+w;
                qwq.push((node){v,dis[v]});
            }
        }
    }
}

int main()
{
    cin>>n>>m>>s;
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }
    
    dijkstra();
    for(int i=1;i<=n;i++)printf("%d ",dis[i]);
    return 0;
}