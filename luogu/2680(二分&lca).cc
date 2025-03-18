#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 300010;
const int MAXM = MAXN-1;
struct Edge{int v,w,next;}edge[MAXM<<1];
struct K{int u,v,lcaa,diss;}lu[MAXN<<1];
int dep[MAXN],dis[MAXN],fa[MAXN][25];
int n,m,max0,tot,head[MAXN],temp[MAXN];
int num[MAXN];

inline void addedge(int x,int y,int z)
{
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

int cnt=0;
inline void lcainit(int x)
{
    num[++cnt]=x;
    for(int i=1;i<=max0;i++)
    if(fa[x][i-1])fa[x][i]=fa[fa[x][i-1]][i-1];
    else break;
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].v;
        if(y!=fa[x][0]){
            fa[y][0]=x;
            dep[y]=dep[x]+1;
            dis[y]=dis[x]+edge[i].w;
            lcainit(y);
        }
    }
}

inline int lca(int u,int v)
{
    if(dep[u]<dep[v])swap(u,v);
    int delta=dep[u]-dep[v];
    for(int x=0;x<=max0;x++)
    if((1<<x)&delta)u=fa[u][x];
    if(u==v)return u;
    for(int x=max0;x>=0;x--)
    if(fa[u][x]!=fa[v][x])
    {
        u=fa[u][x];
        v=fa[v][x];
    }
    return fa[u][0];
}

inline bool check(int mid)
{
    int cnt=0,ans=0;
    memset(temp,0,sizeof(temp));
    for(int i=1;i<=m;i++)
    {
        if(lu[i].diss>mid){
            temp[lu[i].u]++;temp[lu[i].v]++;
            temp[lu[i].lcaa]-=2;
            ans=max(ans,lu[i].diss-mid);
            cnt++;
        }
    }
    if(!cnt)return true;
    for(int i=n;i>=1;i--)
    temp[fa[num[i]][0]]+=temp[num[i]];
    for(int i=2;i<=n;i++)
    if(temp[i]==cnt&&dis[i]-dis[fa[i][0]]>=ans)return true;
    return false;
}

int main()
{
    scanf("%d%d",&n,&m);
    int left=0,right=0,mid;
    for(int i=1;i<n;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);addedge(y,x,z);
        right+=z;
    }
    
    max0=(int)(log(n)/log(2))+3;
    lcainit(1);
    
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&lu[i].u,&lu[i].v);
        lu[i].lcaa=lca(lu[i].u,lu[i].v);
        lu[i].diss=dis[lu[i].u]+dis[lu[i].v]-2*dis[lu[i].lcaa];
    }
    
    while(left<right)
    {
        mid=(left+right)>>1;
        if(check(mid))right=mid;
        else left=mid+1;
    }
    
    printf("%d",left);
    return 0;
}
