#include<bits/stdc++.h>
#define MAXN 500015
#define MAXM MAXN-1
using namespace std;

int n,m,s,max0;
int tot,head[MAXN<<1],dep[MAXN<<1];
int fa[MAXN<<1][40];

struct node{
    int u,v;
    int next;
}edge[MAXM<<1];

void addedge(int x,int y)
{
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

void dfs(int x)
{
    for(int i=1;i<=max0;i++)
    if(fa[x][i-1]) fa[x][i]=fa[fa[x][i-1]][i-1];
    else break;
    
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].v;
        if(y!=fa[x][0]){
            fa[y][0]=x;
            dep[y]=dep[x]+1;
            dfs(y);
        } 
    }
}

int LCA(int u,int v)
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

int main()
{
    scanf("%d%d%d",&n,&m,&s);
    max0=(int)(log(n)/log(2))+5;
    
    int x,y;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);
        addedge(y,x);
    }
    dfs(s);
    int a,b;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a,&b);
        printf("%d\n",LCA(a,b));
    }
    
    return 0;
}