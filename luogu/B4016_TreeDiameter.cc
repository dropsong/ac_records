// link: https://www.luogu.com.cn/problem/B4016
// github: https://github.com/dropsong

#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 1e5+10;
bool vis[MAXN];
struct Edge{int v,w,next;}edge[2*(MAXN-1)];
int tot, head[MAXN], n;

struct node{
	int dis, i;
	bool operator < (const node &rhs) const
	{
		return dis < rhs.dis;
	}
};

inline void addedge(int x, int y, int z)
{
	edge[++tot].v = y;
	edge[tot].w = z;
	edge[tot].next = head[x];
	head[x] = tot;
}


// dfs(x) 返回未访问的节点中到 x 最远的节点的距离，以及这个节点的编号
node dfs(int x)
{
	vis[x] = true;
	node tmp{0, x};
	for(int i = head[x]; i; i=edge[i].next)
	{
		int y = edge[i].v;
		if(vis[y]) continue;
		node tmp2 = dfs(y);
		int dis2 = tmp2.dis, i2 = tmp2.i;
        tmp = std::max(tmp, (node){dis2+edge[i].w, i2});
	}
	return tmp;
}


int main()
{
	scanf("%d", &n);
	for(int i = 1; i < n; ++i)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		addedge(x, y, 1); addedge(y, x, 1);
	}

	node tmp1 = dfs(1);
	memset(vis, false, sizeof(vis));
	node tmp2 = dfs(tmp1.i);
	printf("%d", tmp2.dis);

	return 0;
}
