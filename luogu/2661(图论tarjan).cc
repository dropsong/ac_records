#include<iostream>
const int maxn=200005;
using namespace std;

int t[maxn],in[maxn];
int vis[maxn],len;

void del(int u)
{
    int v=t[u];
    t[u]=0; in[v]--;
    if(!in[v]) del(v);
}

void dfs(int u)
{
    vis[u]=true;
    ++len;
    int v=t[u];
    if(!vis[v])dfs(v);
}

int main()
{
    int n; cin>>n;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&t[i]);
        in[t[i]]++; 
    }
    for(int i=1;i<=n;i++)
    if(!in[i]) del(i);
    
    int ans=maxn;
    for(int i=1;i<=n;i++)
    if((!vis[i])&&in[i])
    {
        dfs(i);
    	ans=min(ans,len);
        len=0;
    }
    
    cout<<ans;
    return 0; 
}