#include <cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

const int maxn = 1e5+3;
const int maxm = maxn-1;
struct Edge{int v,w,next;}edge[maxm<<1];
int head[maxn],tot,dis[maxn];
int n,m,ans,cnt=1,nex[maxn<<5][2];

inline void addedge(int x,int y,int z){
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

void insert(int x){
    for(int i=30,p=1;~i;i--){
        int c = ((x>>i)&1); //二进制从（权值）高位向低位取
        if(!nex[p][c])nex[p][c]=++cnt;
        p=nex[p][c];
    }
}

void get(int x){
    int res = 0;
    for(int i=30,p=1;~i;i--){
        int c = ((x>>i)&1);
        if(nex[p][c^1]){  //贪心
            p=nex[p][c^1];
            res |= (1<<i);
        }
        else p=nex[p][c];
    }
    ans=MAX(ans,res);
}

void dfs(int x, int fa){
    insert(dis[x]);
    get(dis[x]);
    for(int i=head[x];i;i=edge[i].next){
        int y=edge[i].v;
        if(y==fa)continue;
        dis[y]=dis[x]^edge[i].w;
        dfs(y,x);
    }
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
        addedge(y,x,z);
    }

    dfs(1,0);

    printf("%d",ans);
    return 0;
}