#include<bits/stdc++.h>
#define MAXN 2005
#define MAXM 10005
using namespace std;

int n,m;
int uset[MAXN];
struct node{
    int u,v,w;
}edge[MAXM];

bool cmp(node x,node y){return x.w<y.w;}

inline void makeset(int size){
    for(int i=0;i<size;i++)uset[i]=i;
}

int find(int x){
    if(uset[x]!=x)uset[x]=find(uset[x]);
    return uset[x];
}

inline void unionset(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    uset[x]=y;
}

int main()
{
    cin>>n>>m;
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
    
    int cnt=0;
    for(int i=1;i<=m;i++)
    {
        x=find(edge[i].u);
        y=find(edge[i].v);
        if(x==y)continue;
        if(++cnt==n-1){
            cout<<edge[i].w;
            return 0;
        }
        unionset(x,y);
    }
}
