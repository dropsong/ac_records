#include<bits/stdc++.h>
#define M 100005
using namespace std;
int a[M],s[M],n;
int main()
{
    scanf("%d",&n);
    int ave=0;
    for (int i=1;i<=n;i++)
        scanf("%d",&a[i]),ave+=a[i];
    ave/=n;
    for (int i=1;i<=n;i++)
        s[i]=s[i-1]+a[i]-ave;
    sort(s+1,s+1+n);
    long long ans=0;
    for (int i=1;i<=n;i++)
        ans=ans+abs(s[i]-s[(n+1)/2]);
    printf("%lld\n",ans);
    return 0;
}