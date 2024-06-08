#include<bits/stdc++.h>
using namespace std;

const int MAXN =1e5+10;
const int MAXM =1e5+10;
int head[MAXN],head2[MAXN];
int dfn[MAXN],low[MAXN],id[MAXN];
int cnt,sum[MAXN],dp[MAXN];
int stac[MAXN],add[MAXN];
int n,num,top,tot,tot2;
bool ins[MAXN],vis[MAXN];

struct Edge{
    int v,next;
}edge[MAXM];

struct Edgeid{
    int v,next;
}edgeid[MAXM];

void addedge(int x,int y)
{
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

void addid(int x,int y)
{
    edgeid[++tot2].v=y;
    edgeid[tot2].next=head2[x];
    head2[x]=tot2;
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
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int y;scanf("%d",&y);
        addedge(i,y);
    }
}

int dfs(int x)
{
    if(dp[x])return dp[x];
    vis[x]=true;
    for(int i=head2[x];i;i=edgeid[i].next)
    dp[x]+=dfs(edgeid[i].v);
    dp[x]+=sum[x];
    return dp[x];
}

int main()
{
    input();
    for(int i=1;i<=n;i++)
    if(!dfn[i])tarjan(i);
    
    for(int x=1;x<=n;x++)
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].v;
        if(id[x]!=id[y])addid(id[x],id[y]);
    }
    /*
    //========test==========
    cout<<"cnt= "<<cnt<<endl;
    for(int i=1;i<=cnt;i++)
    {
    	cout<<"cnt"<<i<<":"<<"  ";
    	for(int j=1;j<=n;j++)
    	if(id[j]==i)cout<<j<<" ";
    	cout<<endl;
    }
    
    cout<<endl;
    for(int x=1;x<=cnt;x++)
    {
    	cout<<"sum[x]="<<sum[x]<<endl;
    	cout<<x<<" dao da de dian: ";
    	for(int i=head2[x];i;i=edgeid[i].next)
    	cout<<edgeid[i].v<<" ";
    	cout<<endl;
    	
    }
    
    //return 0;
    //========test==========
    */
    for(int x=1;x<=cnt;x++)
    if(!vis[x])dfs(x);
    
    for(int i=1;i<=n;i++)
    printf("%d\n",dp[id[i]]);
    return 0;
}
