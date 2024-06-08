#include<bits/stdc++.h>
#define maxm 6210
#define maxn 2510
#define INF 2147483647
using namespace std;

struct node{
    int u,v,w;
    int next;
}edge[maxm<<1];
int n,m,s,e;
int tot,head[maxn];
int dis[maxn];
bool inq[maxn];

void addedge(int x,int y,int z){
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

void spfa()
{
    queue<int> qwq;
    for(int i=1; i<=n; i++) 
    dis[i]=INF;
    
    qwq.push(s); dis[s]=0; inq[s]=true;
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
                if(!inq[y]){qwq.push(y);inq[y]=true;}
            }
        }
    }
}

int main()
{
    scanf("%d%d%d%d",&n,&m,&s,&e);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }
    
    spfa();
    
    printf("%d",dis[e]);
    return 0;
} 