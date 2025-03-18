#include<stdio.h>
#include<algorithm>
#define lowbit(x) (x&(-x))
using namespace std ;

const int MAXN = 500100;
struct zxx{int l,r,id;}a[MAXN];
int pre[MAXN],col[MAXN],c[MAXN];
int ans[MAXN],last[4000100],n;

void update(int i,int value){
    while(i<=n)
    {
        c[i]+=value;
        i+=lowbit(i);
    }
}

int sum(int i){
    int s=0;
    while(i){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

int cmp(zxx x,zxx b){return x.r<b.r;}

int main()
{
    scanf("%d",&n) ;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&col[i]);
        pre[i]=last[col[i]];
        last[col[i]]=i;
    }
    
    int m; scanf("%d",&m);
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&a[i].l,&a[i].r);
        a[i].id=i;
    }
    
    sort(a+1,a+1+m,cmp);
    
    int now=0;
    for(int i=1;i<=m;i++)
    {
        while(now<a[i].r){
            now++;
            update(pre[now]+1,1);
            if(now!=n){update(now+1,-1);}
        }
        ans[a[i].id]=sum(a[i].l);
    }
    
    for(int i=1;i<=m;i++)printf("%d\n",ans[i]);
    return 0;
}
