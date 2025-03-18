#include<bits/stdc++.h>
using namespace std;

const int MAXN =10000+10;
const int MAXM =50000+10;
int head[MAXN],tot;
int dfn[MAXN],low[MAXN];
int cnt,id[MAXN],sum[MAXN];
int out[MAXN],stac[MAXN];
int n,m,num,top;
bool ins[MAXN];

struct Edge{
    int v,next;
}edge[MAXM];

void addedge(int x,int y)
{
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

void tarjan(int x)
{
    dfn[x]=low[x]=++num;  //time tag
    stac[++top]=x; ins[x]=true;
    for(int i=head[x];i;i=edge[i].next)
    if(!dfn[edge[i].v])
    {
        tarjan(edge[i].v);
        low[x]=min(low[x],low[edge[i].v]);
    }
    else if(ins[edge[i].v])
    low[x]=min(low[x],dfn[edge[i].v]);
    
    if(dfn[x]==low[x])
    {
        ++cnt; int y;
        do{
            y=stac[top--],ins[y]=false;
            id[y]=cnt; sum[cnt]++;
        }while(x!=y);
    }
    
}

inline void input()
{
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(x,y);
    }
}

int main()
{
    input();               //O(m)
    for(int i=1;i<=n;i++)
    if(!dfn[i])tarjan(i);  //O(n)
    
    for(int x=1;x<=n;x++)
    for(int i=head[x];i;i=edge[i].next)//O(n)<O(?)<<O(n^2)
    {
        int y=edge[i].v;
        if(id[x]!=id[y])out[id[x]]++;
    }
    
    int k=0;
    for(int i=1;i<=cnt;i++)  //<<O(n)
    {
        if(!out[i])
        {
            if(k){putchar('0');return 0;}
            k=i;
        }
    }
    
    printf("%d",sum[k]);
    return 0;
}
