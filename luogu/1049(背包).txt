#include<bits/stdc++.h>
#define MAXN 20010
using namespace std;

int c[MAXN];
int f[MAXN];
int n,m;

int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;i++)
    scanf("%d",&c[i]);
    
    for(int i=1;i<=m;i++)
    {
        for(int v=n;v>=c[i];v--)
        f[v]=max(f[v],f[v-c[i]]+c[i]);
    }
    
    cout<<n-f[n];
    return 0;
}