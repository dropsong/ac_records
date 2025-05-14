// link: https://www.luogu.com.cn/problem/P3478

#include <cstdio>

const int MAXN = 1e6+5;
const int MAXM = MAXN - 1;
struct Edge{int v, next;}edge[MAXM*2];
int tot, head[MAXN], n, size[MAXN];
long dep[MAXN], f[MAXN];


inline void addedge(int x, int y){
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}


// 计算 size[]
int dfs_size(int x, int fa)
{
    size[x] = 1;
    dep[x] = dep[fa] + 1;
    for(int i = head[x]; i; i = edge[i].next)
    {
        int y = edge[i].v;
        if(y == fa) continue;
        size[x] += dfs_size(y, x);
    }
    return size[x];
}


// 计算以 x 为根的深度和
// f[son]=f[fa]-size[son]+n-size[son]
void dfs_ans(int x, int fa)
{
    for(int i = head[x]; i; i = edge[i].next)
    {
        int y = edge[i].v;
        if(y == fa) continue;
        f[y] = f[x] - 2*size[y] + n;
        dfs_ans(y, x);
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
    }

    dfs_size(1, 0);
    for(int i = 1; i <= n; ++i) f[1] += dep[i];
    dfs_ans(1, 0);

    long ans = 0;  int ans_id = -1;
    for(int i = 1; i <= n; ++i)
        if(ans < f[i])
            ans = f[i], ans_id = i;
    
    printf("%d", ans_id);
    return 0;
}