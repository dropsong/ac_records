#include<bits/stdc++.h>
using namespace std;

const int MAXM=50000+5;
const int MAXN=300+5;
int n,m,uset[MAXN];
struct Edge{
    int u,v,w;
}edge[MAXM];

void makeset(int size){
    for(int i=0;i<size;i++)uset[i]=i;
}

int find(int x){
    if(uset[x]!=x)uset[x]=find(uset[x]);
    return uset[x];
}

void unionset(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    uset[x]=y;
}

bool cmp(Edge x,Edge y){
    return x.w<y.w;
}

int main()
{
    scanf("%d%d",&n,&m);
    int x,y,z;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d%d",&x,&y,&z);
        edge[i].u=x;
        edge[i].v=y;
        edge[i].w=z;
    }
    
    sort(edge+1,edge+1+m,cmp);
    makeset(n+1);
    
    int cnt=0,maxf=-1;
    for(int i=1;i<=m;i++)
    {
        x=find(edge[i].u);
        y=find(edge[i].v);
        if(x==y)continue;
        maxf=max(maxf,edge[i].w);
        if(++cnt==n-1)break;
        unionset(x,y);
    }
    
    printf("%d %d",n-1,maxf);
    return 0;
}
