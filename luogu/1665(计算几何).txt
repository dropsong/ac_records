#include<cstdio>
using namespace std;

int n,ans;
int x[10000],y[10000],rainman[1111][1111];
bool vis[1111][1111];

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int n;scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d%d",&x[i],&y[i]);
        x[i]=(x[i]+53)<<1;
        y[i]=(y[i]+53)<<1; //ÀëÉ¢»¯ 
        vis[x[i]][y[i]]=true;
    }
    
    for(int i=1;i<=n;i++)
    for(int j=i+1;j<=n;j++)
    {
        int menci=(x[i]+x[j])>>1;
        int nriobc=(y[i]+y[j])>>1;
        int x1=menci-(nriobc-y[i]),y1=nriobc+menci-x[i];
        int x2=menci+nriobc-y[i],y2=nriobc-menci+x[i];
        if(x1<=0||x2<=0)continue;
        if(y1<=0||y2<=0)continue;
        if(vis[x1][y1]&&vis[x2][y2])ans++;
    }
    
    printf("%d",ans>>1);
    return 0;
}
