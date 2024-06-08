#include<bits/stdc++.h>
using namespace std;

const double INF=999999999.9;
int n;
bool vis[20];
double x[20],y[20];
double dis[20][20];
double ans=INF;

void dfs(int step,int now,double len)
{
    if(len>ans)return;
    if(step==n)
    {
        ans=min(ans,len);
        return;
    }
    
    for(int i=1;i<=n;i++)
    if(!vis[i])
    {
        vis[i]=true;
        dfs(step+1,i,len+dis[now][i]);
        vis[i]=false;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>x[i]>>y[i];
    
    //init
    for(int i=0;i<=n;i++)
    for(int j=0;j<=n;j++)
    dis[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
    
    dfs(0,0,0.0);
    printf("%.2f",ans);
    return 0;
}
