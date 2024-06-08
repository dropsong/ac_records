//每一个不曾ac的日子都是一种遗憾
#include<bits/stdc++.h>
#define MAXN 10010
using namespace std;
int w[MAXN];
int f[MAXN];
int main()
{
    int n,m;
    cin>>n>>m;
    f[0]=1;
    for(int i=1;i<=n;++i)
    cin>>w[i];
    
    for(int i=1;i<=n;++i)
    for(int j=m;j>=w[i];--j)
    f[j]+=f[j-w[i]];
    cout<<f[m]<<endl;
    
    return 0;
}