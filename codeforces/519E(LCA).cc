#include<bits/stdc++.h>
#define MAXN 500015
#define MAXM MAXN-1
using namespace std;

int n,max0,d,tot,x,y,tempu,tempv;
int size[MAXN],head[MAXN],dep[MAXN];
int fa[MAXN<<1][20];

struct node{
    int u,v,next;
}edge[MAXM<<1];

inline void addedge(int x,int y)
{
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

inline void input()
{
    scanf("%d",&n);
    max0=(int)(log(n)/log(2))+3;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);addedge(y,x);
    }
}

int lcainit(int x)
{
    for(int i=1;i<=max0;i++)
    if(fa[x][i-1]) fa[x][i]=fa[fa[x][i-1]][i-1];
    else break;
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].v;
        if(y!=fa[x][0])
        {
            fa[y][0]=x;dep[y]=dep[x]+1;
            size[x]+=lcainit(y);
        } 
    }
    return size[x];
}

inline int LCA(int u,int v)
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
    tempu=u; tempv=v;
    return fa[u][0];
}

int main()
{
    for(int i=0;i<MAXN;i++) size[i]=1;
    input();
    lcainit(1);
    int m; cin>>m;
    while(m--)
    {
        scanf("%d%d",&x,&y);
        if(x==y){printf("%d\n",n);continue;}
        int lca=LCA(x,y);
        if(dep[x]<dep[y])swap(x,y);
        d=dep[x]+dep[y]-(dep[lca]<<1);
        if(d&1) {printf("0\n");continue;}
        if(dep[x]==dep[y])
        {
            int ans=n-size[tempu]-size[tempv];
            printf("%d\n",ans); continue;
        }
        int delta=d>>1;
        int midson,mid;
        for(int i=max0;i>=0;i--)
    	{
    		if((1<<i)&(delta-1))
    		x=fa[x][i],delta-=(1<<i);
    		if(delta==1)
    		midson=x,mid=fa[x][0];
    	}
    	int ans=size[mid]-size[midson];
    	printf("%d\n",ans);
    }
    return 0;
}