#include<cstdio>
#include<queue>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

const int MAXN = 10010;
const int MAXM = 101000;
int n,w[MAXN],tot,head[MAXN];
struct Edge{int v,next;}edge[MAXM];
int in[MAXN],t[MAXN],ans;

inline void addedge(int x,int y)
{
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

inline void toposort()
{
    queue<int> qwq;
    for(int i=1;i<=n;i++)
    if(!in[i])qwq.push(i);
    while(!qwq.empty())
    {
        int x=qwq.front();qwq.pop();
        t[x]+=w[x];
        for(int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].v;
            t[y]=MAX(t[y],t[x]);
            if(--in[y]==0)qwq.push(y);
        }
    }
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int temp; scanf("%d",&temp);
        scanf("%d",&w[i]);
        while(scanf("%d",&temp)&&temp){
            addedge(temp,i);
            in[i]++;
        }
    }
    
    toposort();
    
    for(int i=1;i<=n;i++)
    ans=MAX(ans,t[i]);
    
    printf("%d",ans);
    return 0;
}
