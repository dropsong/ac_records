#include<stdio.h>
#include<algorithm>
#define MAXN 310
using namespace std;

int n;
struct peo{
    int ch;
    int ma;
    int en;
    int total;
    int index;
};
peo a[MAXN];

bool cmp(peo x,peo y){
    if(x.total>y.total)return true;
    if(x.total<y.total)return false;
    if(x.ch>y.ch)return true;
    if(x.ch<y.ch)return false;
    return x.index<y.index;
}

int main()
{
    //freopen(".in"."r",stdin);
    //freopen(".out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        a[i].index=i;
        scanf("%d",&a[i].ch);
        scanf("%d",&a[i].ma);
        scanf("%d",&a[i].en);
        a[i].total=a[i].ch
          +a[i].ma+a[i].en;
    }
    
    sort(a+1,a+1+n,cmp);
    
    for(int i=1;i<=5;i++)
    {
        printf("%d ",a[i].index);
        printf("%d\n",a[i].total);
    }
    
    return 0;
}
