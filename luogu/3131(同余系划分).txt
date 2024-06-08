#include<cstdio>
long long a[50003],b[50003];
int main()
{
    int n,maxn=-1;
    scanf("%d",&n);
    for(int k=1;k<=n;k++)
    {
        scanf("%lld",&a[k]);
        a[k]+=a[k-1];
        b[k]=a[k]%7;
    }
    bool ok;
    int l,r;
    for(int temp=0;temp<=6;temp++)
    {
        l=-1;r=-1;ok=true;
        for(int k=1;k<=n;k++)
        {
            if(ok&&b[k]==temp)
            {
                ok=false;
                l=k;
            }
            if(b[k]==temp&&k>r)r=k;
        }
        if(r-l>maxn)maxn=r-l;
    }
    printf("%d",maxn);
    return 0;
}