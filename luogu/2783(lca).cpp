#include <cstdio>
#include <cmath>
#include <algorithm>
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int maxn=1e4+3;
const int maxm=1e5+3;
// Edge_number in a general graph is twice that of a one-way graph
struct Edge{int v,next;};
Edge edge[maxm],edge2[maxm];
int head[maxn],dfn[maxn],low[maxn],stac[maxn],color[maxn],fa[maxn];
int n,m,tot,num,top,cnt,tot_in_txt,lcafa[maxn][25];
int head2[maxn],tot2,dep[maxn],max0;
bool ins[maxn], vis[maxn];

const int topow[] = {1,2,4,8,16,32,64,128,256,512,1024,2048,4096,8192};

inline void rd(int &x){
    int w=x=0;
    char ch=0;
    while(ch<'0'||'9'<ch) w|=(ch=='-'),ch=getchar();
    while('0'<=ch&&ch<='9') x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=w?-x:x;
}

inline void addedge(int x,int y){
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

inline void addedge2(int x,int y){
    edge2[++tot2].v=y;
    edge2[tot2].next=head2[x];
    head2[x]=tot2;
}

void tarjan(int x){
    low[x]=dfn[x]=++num;
    stac[++top]=x; ins[x]=true;
    for(int i=head[x];i;i=edge[i].next){
        int y=edge[i].v;
        if(!dfn[y]){
            fa[y]=x;
            tarjan(y);
            low[x]=MIN(low[x],low[y]);
        }
        else if(ins[y] && y!=fa[x]){
            low[x]=MIN(low[x],dfn[y]);
        }
    }
    if(dfn[x]==low[x]){
        ++cnt; int y;
        do{
            y=stac[top--]; ins[y]=false;
            color[y]=cnt;
        }while(x!=y);
    }
}

void lcainit(int x){
    vis[x] = true;
    for(int i=1;i<=max0;i++)
        if(lcafa[x][i-1])lcafa[x][i]=lcafa[lcafa[x][i-1]][i-1];
        else break;

    for(int i=head2[x];i;i=edge2[i].next){
        int y=edge2[i].v;
        if(y!=lcafa[x][0]){
            lcafa[y][0]=x;
            dep[y]=dep[x]+1;
            if(!vis[y]) lcainit(y);
        }
    }
}

inline int lca(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    int delta=dep[u]-dep[v];
    for(int x=0;x<=max0;x++)
        if((1<<x)&delta)u=lcafa[u][x];
    if(u==v)return u;
    for(int x=max0;x>=0;x--)
        if(lcafa[u][x]!=lcafa[v][x]){
            u=lcafa[u][x];
            v=lcafa[v][x];
        }
    return lcafa[u][0];
}

int main(){
    rd(n); rd(m);
    for(int i=1;i<=m;i++){
        int x,y;
        rd(x); rd(y);
        addedge(x,y);
        addedge(y,x);
    }
    rd(tot_in_txt);

    for(int i=1;i<=n;i++){
        if(!dfn[i])tarjan(i);
    }

    for(int x=1;x<=n;x++){
        for(int i=head[x];i;i=edge[i].next){
            int y=edge[i].v;
            if(color[x]!=color[y]){
                addedge2(color[x], color[y]);
                addedge2(color[y], color[x]);
            }
        }
    }

    max0=(int)(log(cnt)/log(2))+3;
    lcainit(1);

    while(tot_in_txt--){
        int a,b;
        rd(a); rd(b);
        int k = lca(color[a], color[b]);
        int temp = dep[color[a]] + dep[color[b]] - (dep[k]<<1) + 1;

        char ans[15] = "00000000000000";
        for(int i=13; ~i; i--){
            if(temp>=topow[i]){
                ans[13-i] = '1';
                temp -= topow[i];
            }
        }
        int i = 0;
        while(ans[i]=='0') i++;
        for(; i<=13; i++)putchar(ans[i]);
        putchar('\n');
    }

    return 0;
}