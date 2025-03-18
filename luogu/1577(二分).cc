#include<stdio.h>
#include<algorithm>
#define HOME
#define TEST printf("a test.\n")
#define MAXN 10010
using namespace std;
int a[MAXN],l=1,r,mid,n,k;

inline bool judge(int x)
{
    int sum=0;
    for(int i=1;i<=n;i++)
        sum+=a[i]/x;
    return sum>=k;
}

int main()
{
#ifdef NOIP
    freopen(".in","r","stdin");
    freopen(".out","w","stdout");
#endif
    int maxn=-1;
    scanf("%d%d",&n,&k);
    for(register int i=1;i<=n;i++)
    {
        float temp;
        scanf("%f",&temp);
        a[i]=100*temp;
        maxn=max(a[i],maxn);
    }r=maxn;
    
    while(l<=r)
    {
        mid=(l+r)/2;
        if(judge(mid))l=mid+1;
        else r=mid-1;
    }
    float temp2;
    temp2=l-1;temp2/=100;
    printf("%.2f\n",temp2);
    
    return 0;
}