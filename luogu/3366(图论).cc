#include<bits/stdc++.h>
using namespace std;

const int M =200010;
struct node
{
  int u,v,w;
}Q[M];
int fa[M];

bool cmp(node a,node b){return a.w<b.w;}
 
int find(int v){
    if(fa[v]!=v)fa[v]=find(fa[v]);
    return fa[v];
}
 
int main()
{
    int i,j,n,m,x,y;
    scanf("%d%d",&n,&m);
    for(i=1;i<=m;i++)
    {
        cin>>Q[i].u;cin>>Q[i].v;cin>>Q[i].w;
    }
    sort(Q+1,Q+m+1,cmp);
    for(i=1;i<=n;i++) fa[i]=i;
 
    int sum=0,cut=0;
    for(i=1;i<=m;i++)
    {
        x=find(Q[i].u);
        y=find(Q[i].v);        
        if(x==y)continue;        
        sum+=Q[i].w;        
        if(++cut==n-1)break;        
        fa[x]=y;    
    }    
    printf("%d",sum);
    if(!sum)printf("orz");
    return 0;
}