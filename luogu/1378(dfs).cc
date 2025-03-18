#include<bits/stdc++.h>
#define pi (double)acos(-1.0)
using namespace std;

struct point
{
    int x,y;
    void input()
    {
        scanf("%d%d",&x,&y);
    }
};

point rag1,rag2,a[10];
int n,kase[10];
bool vis[10],ocu[10];
double dis[10][10],r[10];
double sums,ans;

inline double sqr(double x){return x*x;}
inline double ABS(double x){return x>=0.0?x:(-x);}

double check(int x)
{
    double temp=min(ABS(a[x].x-rag1.x),ABS(a[x].x-rag2.x));
    temp=min(temp,ABS(a[x].y-rag1.y));
    temp=min(temp,ABS(a[x].y-rag2.y));
    return temp;
}

void dfs(int cur)
{
    if(cur==n)
    {
        memset(r,0,sizeof(r));
        memset(ocu,false,sizeof(ocu));
        for(int k=0;k<n;k++)
        {
            int x=kase[k];
            if(ocu[x])continue;
            double temp=DBL_MAX;
            for(int j=1;j<=n;j++)
            if(j!=x&&r[j]>0)temp=min(temp,dis[x][j]-r[j]);
            temp=min(temp,check(x));
            r[x]=temp;
            for(int j=1;j<=n;j++)
            if(r[x]>=dis[x][j]&&(j!=x))ocu[j]=true;
        }
        double sumrr=0.0;
        for(int i=1;i<=n;i++)
        sumrr+=sqr(r[i]);
        ans=max(ans,pi*sumrr);
        return;
    }
    for(int i=1;i<=n;i++)
    if(!vis[i]){
        vis[i]=true;
        kase[cur]=i;
        dfs(cur+1);
        kase[cur]=0;
        vis[i]=false;
    }
}

void init()
{
    for(int i=1;i<=n;i++)
    for(int j=1;j<=n;j++)
    dis[i][j]=sqrt(sqr(a[i].x-a[j].x)+sqr(a[i].y-a[j].y));
}

int main()
{
    scanf("%d",&n);
    rag1.input(); rag2.input();
    for(int i=1;i<=n;i++)a[i].input();
    sums=(double)abs((rag1.x-rag2.x)*(rag1.y-rag2.y));
    
    init();
    dfs(0);
    printf("%0.0lf",sums-ans);
    return 0;
}
