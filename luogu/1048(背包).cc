//TEST
#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define MAXN 1008
using namespace std;

int c[MAXN],w[MAXN];
int f[MAXN];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
   
    for(int i=1;i<=m;i++)
    scanf("%d%d",&c[i],&w[i]);
    
    for(int i=1;i<=m;i++)
    {
        for(int v=n;v>=c[i];v--)
        f[v]=max(f[v],f[v-c[i]]+w[i]);
    }
    
    cout<<f[n];
    return 0;
}