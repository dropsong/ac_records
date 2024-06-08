#include<bits/stdc++.h>
#define MAXN 30
using namespace std;

int c[MAXN],w[MAXN];
int f[30005];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
   
     for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&c[i],&w[i]);
        w[i]*=c[i];
    }
    for(int i=1;i<=m;i++)
    {
        for(int v=n;v>=c[i];v--)
        f[v]=max(f[v],f[v-c[i]]+w[i]);
    }
    
    cout<<f[n];
    return 0;
}