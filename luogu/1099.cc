// link: https://www.luogu.com.cn/problem/P1099
// github: https://github.com/dropsong

// TODO
/*
找到直径 O(n)
  - 随便一条直径都可以吗？

//在直径上双指针，两边各设一个已移动长度的计数器，优先移动值小的那边的指针，直到剩余长度小于等于 s

do {
    求偏心距 O(n)
    移动值小的那边的指针
}while(lptr != rptr)   // worst case O(n)

求偏心距 O(n)  // 此时 lptr == rptr，退化为一个点

total: O(n^2)

-------

以上过程中维护最小的偏心距
*/

#include <cstdio>
#include <algorithm>
#include <queue>

const int MAXN = 305;
const int MAXS = 1e3+5;
int n, s;
bool vis[MAXN];
struct Edge{int v,w,next;}edge[2*(MAXN-1)];
int tot,head[MAXN];
std::queue<int> qwq;

struct node{
	int dis, i;
	bool operator < (const node &rhs) const {
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
		tmp = std::max(tmp, (node){dfs(y).dis + edge[i].w, y});
	}
	qwq.push(tmp.i);  // 队头是离 x 最远的节点
	return tmp;
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

	dfs(1);
	int u = qwq.front();  // u 是 1 的一个最远点
	while(!qwq.empty()) qwq.pop();
	dfs(u);


	return 0;
}
