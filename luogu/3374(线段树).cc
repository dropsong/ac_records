#include<bits/stdc++.h>
#define MAXN 500010
#define LL long long
using namespace std;

struct segementtree
{
    LL l,r,sum;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
}tree[MAXN<<2];
LL a[MAXN],n,m;

void build(LL p,LL l,LL r)
{
    l(p)=l; r(p)=r;
    if(l==r){sum(p)=a[l];return;}
    LL mid=((l+r)>>1);
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    sum(p)=sum(p<<1)+sum((p<<1)+1);
}

void changepoint(LL p,LL x,LL y)
{
    if(l(p)==r(p)){sum(p)+=y;return;}
    LL mid=(l(p)+r(p))>>1;
    if(x<=mid)changepoint(p<<1,x,y);
    else changepoint((p<<1)+1,x,y);
    sum(p)=sum(p<<1)+sum((p<<1)+1);
}

LL ask(LL p,LL l,LL r)
{
    if(l<=l(p)&&r>=r(p))return sum(p);
    LL mid=(l(p)+r(p))>>1;
    LL val=0;
    if(l<=mid)val+=ask(p<<1,l,r);
    if(r>mid)val+=ask((p<<1)+1,l,r);
    return val; 
}

int main()
{
    scanf("%lld%lld",&n,&m);
    for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,1,n);
    LL tag,x,y;
    while(m--)
    {
        scanf("%lld%lld%lld",&tag,&x,&y);
        if(tag==1) changepoint(1,x,y);
        else printf("%lld\n",ask(1,x,y));
    }
    
    return 0;
}
