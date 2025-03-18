#include<bits/stdc++.h>
#define MAXN 200005
#define LL long long
using namespace std;

struct segmenttree
{
    LL l,r;
    LL sum,add,mul;
    segmenttree(LL mul=1,LL add=0)
    {
        this->mul=mul;
        this->add=add;
    }
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
    #define mul(x) tree[x].mul
}tree[MAXN<<2];
LL a[MAXN],n,m,ha;

void build(LL p,LL l,LL r)
{
    l(p)=l; r(p)=r;
    if(l==r){sum(p)=a[l]%ha;return;}
    LL mid=((l+r)>>1);
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    sum(p)=(sum(p<<1)%ha+sum((p<<1)+1)%ha)%ha;
}

inline void spread(LL p)
{
    sum(p<<1)=(sum(p<<1)*mul(p))%ha;
    sum(p<<1)+=add(p)*(r(p*2)-l(p*2)+1);
    sum(p<<1)%=ha;
    sum((p<<1)+1)=(sum((p<<1)+1)*mul(p))%ha;
    sum((p<<1)+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
    sum(p*2+1)%=ha;

    mul(p<<1)=(mul(p<<1)*mul(p))%ha;
    mul((p<<1)+1)=(mul((p<<1)+1)*mul(p))%ha;
    add(p<<1)=((add(p<<1)*mul(p))%ha+add(p))%ha;
    add((p<<1)+1)=((add((p<<1)+1)*mul(p))%ha+add(p))%ha;

    mul(p)=1;
    add(p)=0;
}

void changeadd(LL p,LL l,LL r,LL d)
{
    spread(p);
    if(l<=l(p)&&r>=r(p))
    {
        sum(p)=(sum(p)+d*(r(p)-l(p)+1)%ha)%ha;
        add(p)+=d;add(p)%=ha; return;
    }
    LL mid=(l(p)+r(p))>>1;
    if(l<=mid) changeadd(p<<1,l,r,d);
    if(r>mid) changeadd((p<<1)+1,l,r,d);
    sum(p)=(sum(p<<1)%ha+sum((p<<1)+1)%ha)%ha;
}

void changemul(LL p,LL l,LL r,LL d)
{
    spread(p);
    if(l<=l(p)&&r>=r(p))
    {
        sum(p)=sum(p)*d%ha;
        sum(p)%=ha;
        mul(p)*=d;mul(p)%=ha; return;
    }
    LL mid=(l(p)+r(p))>>1;
    if(l<=mid) changemul(p<<1,l,r,d);
    if(r>mid) changemul((p<<1)+1,l,r,d);
    sum(p)=(sum(p<<1)%ha+sum((p<<1)+1)%ha)%ha;
}

LL ask(LL p,LL l,LL r)
{
    if(l<=l(p)&&r>=r(p))return sum(p)%ha;
    spread(p);
    LL mid=(l(p)+r(p))>>1;
    LL val=0;
    if(l<=mid)val=(val+ask(p<<1,l,r)%ha)%ha;
    if(r>mid)val=(val+ask((p<<1)+1,l,r)%ha)%ha;
    return val;
}

int main()
{
    scanf("%lld%lld",&n,&ha);
    for(LL i=1;i<=n;i++)scanf("%lld",&a[i]);
    build(1,1,n);
    scanf("%lld",&m);
    LL tag,x,y,k;
    while(m--)
    {
        scanf("%lld%lld%lld",&tag,&x,&y);
        if(tag==1)
        {
            scanf("%lld",&k);
            changemul(1,x,y,k);
        }
        else if(tag==2)
        {
            scanf("%lld",&k);
            changeadd(1,x,y,k);
        }
        else printf("%lld\n",ask(1,x,y));
    }
    return 0;
}
