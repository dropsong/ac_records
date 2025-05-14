// link: https://www.luogu.com.cn/problem/P3478
// 给出一个 N 个点的树，找出一个点，使该树以这个点为根时，所有点的深度之和最大。

// 该解法基于一个猜想：
// 满足题目要求的点只在度为 1 的节点上。

/*
假设猜想不成立。不妨设满足题意的点为 root
1）root 连着一个度为 1 的点
   将 root 和这个点视为一个整体。若 root 转而选用这个点，显然内部对深度和的贡献不
   变，但是外部点的贡献增加了。因此其实 root 有更优的选择（这个连着的度为 1 的点）
2）root 不连着度为 1 的点
   （这种情况我不知道如何着手）
---------
upd: 猜想成立，证明见 github 仓库相应位置 3478_prove.pdf
*/

#include <cstdio>

const int MAXN = 1e6+5;
const int MAXM = MAXN - 1;
struct Edge{int v, next;}edge[MAXM*2];
int tot, head[MAXN], n, degree[MAXN];


inline void addedge(int x, int y){
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}


void dfs(int x, int fa, long depth, long& sum){
    sum += depth;
    for(int i = head[x]; i; i = edge[i].next){
        int y = edge[i].v;
        if(y == fa) continue;
        dfs(y, x, depth+1, sum);
    }
}


int main()
{
    scanf("%d", &n);
    for(int i = 1; i < n; ++i){
        int u, v;
        scanf("%d%d", &u, &v);
        addedge(u, v);
        addedge(v, u);
        degree[u]++; degree[v]++;
    }

    long ans = -1, ans_node = 0;
    for(int i = 1; i <= n; ++i){
        if(degree[i] == 1){
            long sum = 0;
            dfs(i, 0, 0, sum);
            // printf("%d %d\n", i, sum);
            if(ans < sum){
                ans = sum;
                ans_node = i;
            }
        }
    }

    printf("%ld", ans_node);
    return 0;
}