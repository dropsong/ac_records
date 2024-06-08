#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 310;
const int MAXM = MAXN*MAXN;
int tot,uset[MAXN];
struct Edge{
    int u,v,w;
}edge[MAXM];

int find(int x)
{
    if(uset[x]!=x)uset[x]=find(uset[x]);
    return uset[x];
}

void unionset(int x,int y)
{
    x=find(x); y=find(y);
    if(x==y)return;
    uset[x]=y;
}

bool cmp(Edge x,Edge y){return x.w<y.w;}

int main()
{
    int n; scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        int temp; scanf("%d",&temp);
        edge[++tot].u=0;
        edge[tot].v=i;
        edge[tot].w=temp;
    }
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        int temp; scanf("%d",&temp);
        if(i<=j)continue;
        edge[++tot].u=i;
        edge[tot].v=j;
        edge[tot].w=temp;
    }
    
    sort(edge+1,edge+1+tot,cmp);
    for(int i=0;i<=n;i++)uset[i]=i;
    
    int cnt=0,sum=0;
    int x,y;
    for(int i=1;i<=tot;i++)
    {
        x=find(edge[i].u);
        y=find(edge[i].v);
        if(x==y)continue;
        sum+=edge[i].w;
        if(++cnt==n)break;
        unionset(x,y);
    }
    
    printf("%d",sum);
    return 0;
}