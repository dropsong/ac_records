#include<bits/stdc++.h>
using namespace std;
const int MAXN=10000;
int a[MAXN];
int main()
{
    int kase=0,x,n,q;
    while(scanf("%d%d",&n,&q)==2&&n)
    {
        printf("CASE# %d:\n",++kase);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        sort(a,a+n);
        while(q--)
        {
            scanf("%d",&x);
            int pos=lower_bound(a,a+n,x)-a;
            if(a[pos]==x) printf("%d found at %d\n",x,pos+1);
            else printf("%d not found\n",x);
        }
    }
    return 0;
}