#include<bits/stdc++.h>
using namespace std;

const int MAXN =500+5;
const int MAXM =MAXN*MAXN;
int uset[MAXN],N,n,m;
double ans;

struct node{
    int x,y;
    int index;
}info[MAXN];

struct Edge{
    int u,v;
    double w;
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

bool cmp(Edge x,Edge y){return x.w<y.w;}

int init()
{
    int cnt=0;
    for(int i=1;i<=N;i++)
    for(int j=i+1;j<=N;j++)
    {
        double dis;
        dis=sqrt((info[i].x-info[j].x)*(info[i].x-info[j].x)
           +(info[i].y-info[j].y)*(info[i].y-info[j].y));   
        edge[++cnt].u=info[i].index;
        edge[cnt].v=info[j].index;
        edge[cnt].w=dis;    
    }
    return cnt;
}

int main()
{
    cin>>n>>N;
    int x,y;
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&x,&y);
        info[i].x=x;
        info[i].y=y;
        info[i].index=i;
    }
    
    m=init(); int cnt=0;
    sort(edge+1,edge+1+m,cmp);
    makeset(N+1);
    for(int i=1;i<=m;i++)
    {
        x=find(edge[i].u);
        y=find(edge[i].v);
        if(x==y)continue;
        unionset(x,y);
        ans=max(ans,edge[i].w);
        if(++cnt==N-n)break;
    }
    
    printf("%.2lf",ans);
    return 0;
}

//=========可用对拍程序====================
/******************************************
//code by rainman
#include<bits/stdc++.h>
using namespace std;

const int MAXN =600+5;
const int MAXM =MAXN*MAXN;
int uset[MAXN],N,n,m;
bool flag[MAXN];
double ans=DBL_MAX;

struct node{
    int x,y;
    int index;
}info[MAXN];

struct Edge{
    int u,v;
    double w;
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

bool cmp(Edge x,Edge y){return x.w<y.w;}

int init()
{
    int cnt=0;
    for(int i=1;i<=N;i++)
    for(int j=i+1;j<=N;j++)
    {
        double dis;
        dis=
           sqrt((info[i].x-info[j].x)*(info[i].x-info[j].x)
           +(info[i].y-info[j].y)*(info[i].y-info[j].y));
        
        edge[++cnt].u=info[i].index;
        edge[cnt].v=info[j].index;
        edge[cnt].w=dis;    
    }
    return cnt;
}

void dfs(int cur,int total)
{
    if(total>n)return;
    if(cur==N+1){
        if(total!=n)return;
        makeset(N+10);
        bool one=true; int std;
        for(int i=1;i<=N;i++)
        if(flag[i]){
            if(one){std=i;one=false;continue;}
            unionset(std,i);
        }
        
        int x,y; double d=DBL_MIN;
        for(int i=1;i<=m;i++)
        {
            x=find(edge[i].u);
            y=find(edge[i].v);
            if(x==y)continue;
            d=max(d,edge[i].w);
            unionset(x,y);
        }
        ans=min(ans,d);
        return;
    }
    flag[cur]=true;
    dfs(cur+1,total+1);
    flag[cur]=false;
    dfs(cur+1,total);
}

int main()
{
    cin>>n>>N;
    int x,y;
    for(int i=1;i<=N;i++)
    {
        scanf("%d%d",&x,&y);
        info[i].x=x;
        info[i].y=y;
        info[i].index=i;
    }
    
    m=init();
    sort(edge+1,edge+1+m,cmp);
    dfs(1,0);
    
    printf("%.2lf",ans);
    return 0;
}
***************************************/
