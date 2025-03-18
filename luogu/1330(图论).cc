#include<bits/stdc++.h>
#define MAXM 100010
#define MAXN 10010
using namespace std;

struct node{
    int v,next;
}edge[MAXM<<1];
int tot,head[MAXN];

int sum[2],color[MAXN];
bool vis[MAXN],temp;

void addedge(int x,int y)
{
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

bool bfs(int x)
{
    vis[x]=true;
    sum[color[x]=temp]++;
    queue<int> qwq; qwq.push(x);
    
    while(!qwq.empty())
    {
        int k=qwq.front();qwq.pop();
        temp=!color[k];
        for(int i=head[k];i;i=edge[i].next)
        {
            int y=edge[i].v;
            if(vis[y])
            {
                if(color[y]!=temp)
                return false;
            }
            else{
                vis[y]=true;
                sum[color[y]=temp]++;
                qwq.push(y);
            }
        }
    }
    return true;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n,m;
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    
    int ans=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i])continue;
        sum[0]=sum[1]=0; temp=0;
        memset(color,0,sizeof(color));
        if(!bfs(i)){cout<<"Impossible";return 0;}
        ans+=min(sum[0],sum[1]);
    }
    
    cout<<ans;
    return 0;
}