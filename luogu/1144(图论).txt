#include<cstdio>
#include<queue>
#define HA 100003
using namespace std;

const int MAXN =1000000+5;
const int MAXM =2000000+5;
int tot,head[MAXN];
struct Edge{
    int v,next;
}edge[MAXM<<1];
int ans[MAXN],n,m;
int dis[MAXN];

void addedge(int x,int y)
{
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

void bfs()
{
    queue<int> qwq;
    qwq.push(1);ans[1]=1;dis[1]=0;
    while(!qwq.empty())
    {
        int front=qwq.front();qwq.pop();
        for(int i=head[front];i;i=edge[i].next)
        {
            int y=edge[i].v;
            if(y==front)continue; //ºöÂÔ×Ô»· 
            if(!ans[y])
            {
                ans[y]=ans[y]%HA+ans[front]%HA;
                qwq.push(y);
                dis[y]=dis[front]+1;
            }
            else if(ans[y]&&dis[y]==dis[front]+1)
            ans[y]=ans[y]%HA+ans[front]%HA;
        }
    }
}

int main()
{
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);addedge(y,x);
    }
    
    bfs();
    
    for(int i=1;i<=n;i++)
    printf("%d\n",ans[i]%HA);
    return 0;
}
