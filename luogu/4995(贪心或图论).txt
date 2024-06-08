#include <cstdio>
#include <queue>
using namespace std;
typedef long long LL;

#define int LL
const int N=350,M=210000;
int head[N],tot,done[N],a[N];
long long dis[N];

struct Edge{
    int v,next;
    long long w;
}e[M];

struct node{
    int u,dist;
    bool operator<(const node& v)const
    {
        return dist<v.dist;
    }
};

inline void addedge(int u,int v,long long w)
{
    e[++tot].v=v;
    e[tot].w=w;
    e[tot].next=head[u];
    head[u]=tot;
}

inline void dijkstra(int s)
{
    priority_queue<node> qwq;
    for(int i=0;i<=310;i++)dis[i]=-1;
    dis[s]=0;
    node t, t1;
    t.u=s;t.dist=0;
    qwq.push(t);

    while(!qwq.empty())
    {
        t=qwq.top();qwq.pop();
        if(done[t.u])continue;
        done[t.u]=1;

        for(int i=head[t.u];i;i=e[i].next)
        {
            int v=e[i].v;
            long long w=e[i].w;
            if(dis[v]<dis[t.u]+w)
            {
                dis[v]=dis[t.u]+w;
                t1.dist=dis[v];
                t1.u=v;
                qwq.push(t1);
            }
        }
    }
}       

#undef int
int main()
{
#define int LL
    int n;scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);

    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    {
        addedge(i,j,(a[i]-a[j])*(a[i]-a[j]));
        addedge(j,i,(a[i]-a[j])*(a[i]-a[j]));
    }

    for(int i=1;i<=n;i++)
    {
        addedge(0,i,a[i]*a[i]);
        addedge(i,0,a[i]*a[i]);
        addedge(i,n+1,0);
    }

    dijkstra(0);

    printf("%lld\n",dis[n+1]);
    return 0;
}
