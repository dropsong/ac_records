#include<cstdio>
using namespace std;

int n,m,sum,ans,x[105],a[105];
bool anami[105][105];

void dfs(int now)
{
    if(now>n){
        if(sum<=ans)return;
        ans=sum;
        for(int i=1;i<=n;i++)a[i]=x[i];
        return;
    }
    bool ok=true;
    for(int i=1;i<now;i++)
    if(x[i]&&anami[i][now]){
        ok=false;
        break;
    }
    if(ok){
        x[now]=1;
        sum++;
        dfs(now+1);
        sum--;
        x[now]=0;
    }
    dfs(now+1);
}

int main()
{
    scanf("%d%d",&n,&m);
    int u,v;
    for(int i=1;i<=m;i++){
        scanf("%d%d",&u,&v);
        anami[u][v]=true;
        anami[v][u]=true;
    }
    
    dfs(1); printf("%d\n",ans);
    for(int i=1;i<=n;i++)printf("%d ",a[i]);
    
    return 0;
}
