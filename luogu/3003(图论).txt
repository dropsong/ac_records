#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100000+5;
const int MAXM = 200000+5;
const int INF= 2147483647;
int n,m,s,t1,t2,dis[MAXN];
int tot,head[MAXN];
bool done[MAXN];
struct node{
    int v,w;
    int next;
}edge[MAXM<<1];

struct element{
    int u,dist;
    bool operator< (const element&v)const
    {
        return dist>v.dist;
    }
};
priority_queue<element> qwq;

inline void addedge(int x,int y,int z){
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

void dijkstra(int sindex)
{
    for(int i=1;i<=n;i++)dis[i]=INF;
    memset(done,0,sizeof(done));
    dis[sindex]=0;
    qwq.push((element){sindex,0});
    while(!qwq.empty())
    {
        element front=qwq.top();qwq.pop();
        int u=front.u,dist=front.dist;
        if(done[u])continue;
        done[u]=true;
        for(int i=head[u];i;i=edge[i].next)
        {
            int y=edge[i].v,w=edge[i].w;
            if(dis[u]+w<dis[y])
            {
                dis[y]=dis[u]+w;
                qwq.push((element){y,dis[y]});
            }
        }
    }
}

int main()
{
    cin>>m>>n>>s>>t1>>t2;
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    
    dijkstra(t1);
    int ans1=dis[s]+dis[t2];
    dijkstra(t2);
    int ans2=dis[s]+dis[t1];
    
    cout<<min(ans1,ans2);
    return 0;
}
