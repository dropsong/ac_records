#include<bits/stdc++.h>
#define MAXN 100005
typedef long long LL;
using namespace std;

struct segmenttree
{
    int l,r;
    LL sum,add;
    #define l(x) tree[x].l
    #define r(x) tree[x].r
    #define sum(x) tree[x].sum
    #define add(x) tree[x].add
}tree[MAXN<<2];
int a[MAXN],n,m;

void build(int p,int l,int r)
{
    l(p)=l; r(p)=r;
    if(l==r){sum(p)=a[l];return;}
    int mid=((l+r)>>1);
    build(p<<1,l,mid);
    build((p<<1)+1,mid+1,r);
    sum(p)=sum(p<<1)+sum((p<<1)+1);
}

void spread(int p)
{
    if(add(p))
    {
        sum(p<<1)+=add(p)*(r(p*2)-l(p*2)+1);
        sum((p<<1)+1)+=add(p)*(r(p*2+1)-l(p*2+1)+1);
        add(p<<1)+=add(p);
        add((p<<1)+1)+=add(p);
        add(p)=0;
    }
}

void change(int p,int l,int r,int d)
{
    if(l<=l(p)&&r>=r(p))
    {
        sum(p)+=(LL)d*(r(p)-l(p)+1);
        add(p)+=d; return;
    }
    spread(p);
    int mid=(l(p)+r(p))/2;
    if(l<=mid) change(p<<1,l,r,d);
    if(r>mid) change((p<<1)+1,l,r,d);
    sum(p)=sum(p<<1)+sum((p<<1)+1);
}

LL ask(int p,int l,int r)
{
    if(l<=l(p)&&r>=r(p))return sum(p);
    spread(p);
    int mid=(l(p)+r(p))/2;
    LL val=0;
    if(l<=mid)val+=ask(p<<1,l,r);
    if(r>mid)val+=ask((p<<1)+1,l,r);
    return val; 
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)scanf("%d",&a[i]);
    build(1,1,n);
    int tag,x,y,k;
    while(m--)
    {
        scanf("%d%d%d",&tag,&x,&y);
        if(tag==1)
        {
            scanf("%d",&k);
            change(1,x,y,k);
        }
        else printf("%lld\n",ask(1,x,y));
    }
    
    return 0;
}