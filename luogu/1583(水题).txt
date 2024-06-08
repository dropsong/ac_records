#include<bits/stdc++.h>
#define MAXN 20005
using namespace std;

struct peo{
    int index;
    int w;
};
peo a[MAXN];
int e[11];

bool cmp(peo x,peo y){
    if(x.w==y.w)return x.index<y.index;
    else return x.w>y.w;
}

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=1;i<=10;i++)
    scanf("%d",&e[i]);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].w);
        a[i].index=i;
    }
    
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=n;i++)
    a[i].w+=e[(i-1)%10+1];
    
    sort(a+1,a+1+n,cmp);
    for(int i=1;i<=k;i++)
    printf("%d ",a[i].index);
    
    return 0;
}