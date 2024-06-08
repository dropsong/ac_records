#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cmath>
#include<set>
#include<cstdlib>
#include<queue>
#include<cstring>
#include<string>
#define mian main
#define lowbit(x) (x&(-x))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
using namespace std;
typedef long long LL;
#define int LL

int a[110],t,n,m;
bool vis[25010];

inline void work(int x)
{
    vis[x]=true;
    for(int i=1;i+x<=a[n];i++){
        if(!vis[i])continue;
        vis[i+x]=true;
    }
}

#undef int
int main()
{
#define int LL
    scanf("%lld",&t);
    while(t--){
        scanf("%lld",&n); m=0;
        memset(vis,false,sizeof(vis));
        for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
        sort(a+1,a+1+n);
        if(a[1]==1){puts("1");continue;}
        
        for(int i=1;i<=n;i++){
            if(vis[a[i]])continue;
            work(a[i]); m++;
        }
        printf("%lld\n",m);
    }
    
    return 0;
}
