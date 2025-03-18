#include<bits/stdc++.h>
#define MAXN 100010
#define MAXM MAXN-1
using namespace std;

int xorsum[MAXN];
int fa[MAXN][20],n,max0,m;

struct node{
    int v,w,next;
}edge[MAXM<<1];
int tot,head[MAXN];

inline void addedge(int x,int y,int z)
{
    edge[++tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

inline void input()
{
    scanf("%d",&n);
    max0=(int)(log(n)/log(2))+3;
    int x,y,z;
    for(int i=1;i<n;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);addedge(y,x,z);
    }
}

void lcainit(int x)
{
    for(int i=1;i<=max0;i++)
    if(fa[x][i-1]) fa[x][i]=fa[fa[x][i-1]][i-1];
    else break;
    for(int i=head[x];i;i=edge[i].next)
    {
        int y=edge[i].v;
        if(y!=fa[x][0])
        {
            fa[y][0]=x;
            xorsum[y]=xorsum[x]^edge[i].w;
            lcainit(y);
        } 
    }
}

int main()
{
    input(); scanf("%d",&m);
    lcainit(1);
    int x,y;
    while(m--)
    {
        scanf("%d%d",&x,&y); 
        printf("%d\n",xorsum[x]^xorsum[y]);
    }
    
    return 0;
}
