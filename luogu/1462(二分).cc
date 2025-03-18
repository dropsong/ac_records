#include<cstdio>
#include<queue>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define INF 0x7fffffff
using namespace std;
typedef long long LL;

#define int LL
const int MAXN = 10000+10;
const int MAXM = 50000+10;
struct Edge{int v,w,next;}edge[MAXM<<1];
int tot,head[MAXN],n,m,b,l,r;
int f[MAXN],dis[MAXN];
bool inq[MAXN];

inline void addedge(int x,int y,int z)
{
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

bool spfa(int cost)
{
    if(f[1]>cost)return false;
    for(int i=1;i<=n;i++)dis[i]=INF;
    queue<int> qwq; dis[1]=0;
    qwq.push(1); inq[1]=true;
    
    while(!qwq.empty())
    {
        int x=qwq.front();
        qwq.pop(); inq[x]=false;
        for(int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].v,hp=edge[i].w;
            if(dis[y]>dis[x]+hp&&f[y]<=cost)
            {
                dis[y]=dis[x]+hp;
                if(!inq[y]){
                    qwq.push(y);
                    inq[y]=true;
                }
            }
        }
    }
    if(dis[n]<b)return true;
    return false;
}

#undef int
int main()
{
#define int LL
    scanf("%lld%lld%lld",&n,&m,&b);
    for(int i=1;i<=n;i++)scanf("%lld",&f[i]);
    for(int i=1;i<=n;i++)r=MAX(r,f[i]);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;scanf("%lld%lld%lld",&x,&y,&z);
        if(x==y)continue;
        addedge(x,y,z); addedge(y,x,z);
    }
    l=MAX(f[1],f[n]);
    
    if(!spfa(1000000001)){puts("AFK");return 0;}
    while(l<r)
    {
        int mid=(l+r)>>1;
        if(spfa(mid))r=mid;
        else l=mid+1;
    }
    
    printf("%lld",r);
    return 0;
}
