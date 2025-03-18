#include<bits/stdc++.h>
#define maxm 500010
#define maxn 10010
#define INF 2147483647
using namespace std;

struct node{
    int u,v,w;
    int next;
}edge[maxm];
int n,m,s;
int tot,head[maxn];
int dis[maxn];
bool inq[maxn];

void addedge(int x,int y,int z){
    edge[++tot].u=x;
    edge[tot].v=y;
    edge[tot].w=z;
    edge[tot].next=head[x];
    head[x]=tot;
}

void spfa()
{
    queue<int> qwq;
    for(int i=1; i<=n; i++) 
  	{
    	dis[i]=INF;
    	inq[i]=false;
  	}
    
    qwq.push(s); dis[s]=0; inq[s]=true;
    while(!qwq.empty())
    {
        int x=qwq.front();
        qwq.pop(); inq[x]=false;
        
        for(int i=head[x];i;i=edge[i].next)
        {
            int y=edge[i].v;
            if(dis[y]>dis[x]+edge[i].w)
            {
                dis[y]=dis[x]+edge[i].w;
                if(!inq[y]){qwq.push(y);inq[y]=true;}
            }
        }
    }
}

int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        addedge(x,y,z);
    }
    
    spfa();
    
    for(int i=1;i<=n;i++)
    if(s==i)printf("0 ");
    else printf("%d ",dis[i]);
    
    return 0;
} 