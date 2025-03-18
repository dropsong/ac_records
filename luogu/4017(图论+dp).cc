#include<bits/stdc++.h>
#define BASE 80112002
using namespace std;

const int MAXN = 5000+5;
const int MAXM = 500000+5;
int n,m,ans;
int in[MAXN],out[MAXN];
int head[MAXN],tot;
int f[MAXN];
struct node{
    int v,next;
}edge[MAXM];

inline void addedge(int x,int y){
    edge[++tot].v=y;
    edge[tot].next=head[x];
    head[x]=tot;
}

int dp(int x)
{
    if(f[x])return f[x]%BASE;
    int sum=0;
    for(int i=head[x];i;i=edge[i].next)
    sum=sum%BASE+dp(edge[i].v)%BASE;
    f[x]=sum%BASE;
    return f[x];
}

int main()
{
    cin>>n>>m;
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        addedge(y,x); //·´Ïò½¨±ß 
        in[x]++;out[y]++;
    }
    
    for(int i=1;i<=n;i++)
    if(!out[i])f[i]=1;
    
    for(int i=1;i<=n;i++)
    if(!in[i])ans=(ans%BASE+dp(i)%BASE)%BASE;
    
    cout<<ans%BASE;
    return 0;
}
