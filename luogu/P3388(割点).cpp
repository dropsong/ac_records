#include <cstdio>
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int MAXN = 2e4+3;
const int MAXM = 1e5+3;
int n,m,head[MAXN],tot,ans;
int num,dfn[MAXN],low[MAXN],sroot;
struct Edge{int v,next;}edge[MAXM<<1];
bool iscut[MAXN];

inline void addedge(int x, int y){
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

void tarjan(int x){
    dfn[x]=low[x]=++num;
    int mflag = 0;
    for(int i=head[x];i;i=edge[i].next){
        int y=edge[i].v;
        if(!dfn[y]){
            tarjan(y);
            low[x]=MIN(low[x],low[y]);
            if(low[y]>=dfn[x]){
                mflag++; 
                if(x!=sroot || mflag>1)ans++,iscut[x]=true;
            }
        }
        else low[x]=MIN(low[x],dfn[y]);
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++){
        int x,y; scanf("%d%d",&x,&y);
        if(x==y)continue;
        addedge(x,y); addedge(y,x);
    }

    for(int i=1;i<=n;i++)
        if(!dfn[i])sroot=i,tarjan(i);

    printf("%d\n",ans);
    for(int i=1;i<=n;i++)
        if(iscut[i])printf("%d\n",i);
    
    return 0;
}