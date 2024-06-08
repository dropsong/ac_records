#include<cstdio>
#include<iostream>
#define mod(x,y) (((x)%(y)+(y))%(y))
typedef long long LL;
using namespace std;

//ax+by=gcd(a,b)
LL exgcd(LL a,LL b,LL&x,LL&y)
{
    if(b==0){
        x=1; y=0;
        return a;
    }
    LL r=exgcd(b,mod(a,b),x,y);
    LL temp=x;
    x=y;
    y=temp-a/b*y;
    return r;
}

//ax=b(mod n)
LL MLES(LL a,LL b,LL n)
{
    LL x,y;
    LL d=exgcd(a,n,x,y);
    if(b%d)return -1;
    return mod(x*(b/d),n/d);
}

int main()
{
    LL x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    LL ans=MLES(m-n,y-x,l);
    if(ans==-1)puts("Impossible");
    else printf("%lld",ans);
    return 0;
}
