#include <cstdio>

const int MAXN = 1e5+5;
const int MAXM = MAXN-1;
struct Edge{int v,next;}edge[MAXM<<1];
int tot, head[MAXN], ans, n, d;
bool vis[MAXN];

inline void addedge(int x, int y){
    edge[++tot].v = y;
    edge[tot].next = head[x];
    head[x] = tot;
}

void dfs(int x, int dep){
    if(dep>d) return;
    if(vis[x]) return;
    vis[x] = true;
    ans++;
    for(int i=head[x];i;i=edge[i].next){
        int y=edge[i].v;
        dfs(y,dep+1);
    }
    return;
}

int main(){
    scanf("%d%d",&n,&d);
    for(int i=1; i<n; i++){
        int u, v;
        scanf("%d%d",&u,&v);
        addedge(u,v);
        addedge(v,u);
    }

    dfs(1,0);
    printf("%d",ans-1);
    return 0;
}