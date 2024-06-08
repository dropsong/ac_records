#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

const int MAXN =1e5+10;
const int MAXM =MAXN-1;
int head[MAXN],dep[MAXN];
int n,m,maxdep,tot,index;
bool vis[MAXN];

struct Edge{
	int v,w;
	int next;
}edge[MAXM];

void addedge(int x,int y,int z)
{
	edge[++tot].v=y;
	edge[tot].w=z;
	edge[tot].next=head[x];
	head[x]=tot;
}

void dfs(int x)
{
	vis[x]=true;
	for(int i=head[x];i;i=edge[i].next)
	{
		int y=edge[i].v;
		if(vis[y])continue;
		dep[y]=dep[x]+edge[i].w;
		if(dep[y]>maxdep)maxdep=dep[y],index=y;
		dfs(y);
	}
}

inline void input()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		char s[20];
		scanf("%d%d%d%s",&x,&y,&z,s);
		addedge(x,y,z);
		addedge(y,x,z);
	}
}

int main()
{
	input();
	dfs(1);
	for(int i=1;i<=n;i++)
	dep[i]=0,vis[i]=false;
	maxdep=0;
	dfs(index);
	cout<<maxdep;
	return 0;
}
