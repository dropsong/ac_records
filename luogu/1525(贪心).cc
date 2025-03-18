#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN=20009;
const int MAXM=200019;
struct Edge{int u,v,w;}edge[MAXM];
int n,m,fa[MAXN],Enemy[MAXN];
 
int find(int k)
{
    if(fa[k]==k)return k;
    else return fa[k]=find(fa[k]);
}

bool cmp(Edge x,Edge y){return x.w>y.w;}

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    scanf("%d%d%d",&edge[i].u,&edge[i].v,&edge[i].w);   
    
    for(int i=1;i<=n;i++) fa[i]=i;
    sort(edge+1,edge+1+m,cmp);
    
    for(int i=1;i<=m;i++)
    {
        int t1=find(edge[i].u),t2=find(edge[i].v);
        if(t1==t2)
        {
            printf("%d",edge[i].w);
            return 0;
        }
        
        if(!Enemy[edge[i].u])Enemy[edge[i].u]=edge[i].v;
        else fa[find(Enemy[edge[i].u])]=find(edge[i].v);
        
        if(!Enemy[edge[i].v])Enemy[edge[i].v]=edge[i].u;
        else fa[find(Enemy[edge[i].v])]=find(edge[i].u);      
    }
    
    printf("0");
    return 0;
}
