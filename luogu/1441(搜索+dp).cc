#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20+5;
int n,m,a[MAXN],ans=-233;
bool vis[MAXN],f[2005];

void dfs(int certain,int deserted)
{
    if(deserted>m)return;
    if(certain==n)
    {
        if(deserted==m)  //dp
        {
            memset(f,false,sizeof(f));
            f[0]=true;int cnt=0;  //init
            for(int j=1;j<=n;j++)
            {
                if(vis[j])continue;
                for(int i=n*100;i>=a[j];i--)
                f[i]=f[i-a[j]]||f[i];
            }
            for(int w=1;w<=n*100;w++)
            if(f[w])cnt++;
            ans=max(ans,cnt);
        }
        return;
    }
    
    dfs(certain+1,deserted);
    vis[certain+1]=true;
    dfs(certain+1,deserted+1);
    vis[certain+1]=false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    cin>>a[i];
    dfs(0,0);
    cout<<ans;
    return 0;
}
