#include<bits/stdc++.h>
using namespace std;

const int MAXN =100+5;
const int MAXM =MAXN*MAXN*2;
int n,tot,uset[MAXN];
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
    cin>>n;
    int x,y,z;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    {
        cin>>z;
        edge[++tot].u=i;
        edge[tot].v=j;
        edge[tot].w=z;
        if(i==j)edge[tot].w=INT_MAX;
    }
    
    sort(edge+1,edge+1+tot,cmp);
    makeset(n+1);
    
    int cnt=0,sum=0;
    for(int i=1;i<=tot;i++)
    {
        x=find(edge[i].u);
        y=find(edge[i].v);
        if(x==y)continue;
        sum+=edge[i].w;
        if(++cnt==n-1)break;
        unionset(x,y);
    }
    
    cout<<sum;
    return 0;
}
