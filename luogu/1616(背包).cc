#include<bits/stdc++.h>
#define MAXN 10010
using namespace std;

int t,m;
int ti[MAXN],mi[MAXN];
int f[100005];

int main()
{
    //freopen(".in","w",stdin);
    //freopen(".out","w",stdout);
    
    scanf("%d%d",&t,&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&ti[i],&mi[i]);
        for(int v=0;v<=t;v++)
        {
            if(v-ti[i]<0)continue;
            else
            f[v]=max(f[v],f[v-ti[i]]+mi[i]);
        }
    }
    
    printf("%d",f[t]);
    return 0;
}