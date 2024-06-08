//PS:using data-structure can also solve it.
#include<cstdio>
#define LL long long
using namespace std;

LL a[50010],n,m;

void dfs(LL now,LL y,LL l,LL r)
{
    if(now>n)return;
    if(y>((r-l)*(r-l-1)>>1))
    {
        a[r]=now;
        dfs(now+1,y-r+l,l,r-1);
    }
    else
    {
        a[l]=now;
        dfs(now+1,y,l+1,r);
    }
}

int main()
{
    scanf("%lld%lld",&n,&m);
    dfs(1,m,1,n);
    for(LL i=1;i<=n;i++)printf("%lld ",a[i]);
    return 0;
}