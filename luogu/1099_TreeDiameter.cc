// link: https://www.luogu.com.cn/problem/P1099
// github: https://github.com/dropsong

#include <cstdio>
#include <cstring>
#include <algorithm>
// #define DEBUG

const int MAXN = 305;
const int MAXS = 1e3+5;
bool vis[MAXN];
struct Edge{int v,w,next;}edge[2*(MAXN-1)];
struct node{int dis, i;};
int tot,head[MAXN], n, s, chooooose[MAXN], dis[MAXN][MAXN];


inline void addedge(int x, int y, int z)
{
	edge[++tot].v = y;
	edge[tot].w = z;
	edge[tot].next = head[x];
	head[x] = tot;
}


// dfs(x) 返回未访问的节点中到 x 最远的节点的距离，以及这个节点的编号
node dfs(int x, bool seco)
{
	vis[x] = true;
	node tmp{0, x};
	for(int i = head[x]; i; i=edge[i].next)
	{
		int y = edge[i].v;
		if(vis[y]) continue;
		node tmp2 = dfs(y, seco);
		int dis2 = tmp2.dis, i2 = tmp2.i;
		if(dis2+edge[i].w > tmp.dis)
		{
			tmp = (node){dis2 + edge[i].w, i2};
			if(seco)
			{
				chooooose[x] = y; // i2 is the most distant as defined, y is the next.
				// 每个 x 都要保存下一步选择，而不能反过来找。
				// 因为实际上这个dfs是搜索，需要回溯比较谁最大，不能先验地知道哪个点就是最远的，以及对应的路径
				dis[x][y] = edge[i].w;
			}
		}
	}
	return tmp;
}


int calc_ecc(int x)
{
	vis[x] = true;
	int tmp = 0;
	for(int i = head[x]; i; i = edge[i].next)
	{
		int y = edge[i].v;
		if(vis[y]) continue;
		int tmp2 = calc_ecc(y);
		tmp = std::max(tmp, tmp2+edge[i].w);
	}
	return tmp;
}


int ans = 0x7fffffff;
void work(int x)
{
	if(!x) return;
#ifdef DEBUG
	printf("%d ", x);
#endif

#ifndef DEBUG
	memset(vis, false, sizeof(vis));
	vis[x] = true;
	int dis_from_x = 0, end_point = x, tmp_ecc = 0;
	while(chooooose[end_point] && dis_from_x + dis[end_point][chooooose[end_point]] <= s)
	{
		vis[chooooose[end_point]] = true;
		tmp_ecc = std::max(tmp_ecc, calc_ecc(end_point));
		dis_from_x += dis[end_point][chooooose[end_point]];
		end_point = chooooose[end_point];
	}
	tmp_ecc = std::max(tmp_ecc, calc_ecc(end_point));
	ans = std::min(ans, tmp_ecc);
#endif

	work(chooooose[x]);
}


int main()
{
	scanf("%d%d", &n, &s);
	for(int i = 1; i < n; ++i)
	{
		int x, y, z;
		scanf("%d%d%d", &x, &y, &z);
		addedge(x, y, z); addedge(y, x, z);
	}

	node tmp1 = dfs(1, false);
	memset(vis, false, sizeof(vis));
	node tmp2 = dfs(tmp1.i, true);

#ifdef DEBUG
	printf("dfs1:\n%d %d\n", tmp1.dis, tmp1.i);
	printf("dfs2:\n%d %d\n", tmp2.dis, tmp2.i);

	memset(vis, false, sizeof(vis));
	printf("一条直径：\n");
	work(tmp1.i);
	/*
	5 2
	1 2 5
	2 3 2
	2 4 4
	2 5 3
	9 4
	9 1
	4 2 1
	 */
#endif

#ifndef DEBUG
	work(tmp1.i);
	printf("%d", ans);
#endif

	return 0;
}
