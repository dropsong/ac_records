//题目:[国家集训队]特技飞行
#include<bits/stdc++.h>
#define LL long long
using namespace std;

LL n,k;
LL c[310];

int main()
{
    scanf("%lld%lld",&n,&k);
    for(LL i=1;i<=k;i++)scanf("%lld",&c[i]);
    
    sort(c+1,c+1+k);
    LL l=1,r=n,ans=0;
    for(LL i=k;i>0;i--)
    {
        ans+=(r-l)*c[i];
        l++,r--;
        if(l>=r)break;
    }
    
    printf("%lld",ans);
    return 0;
}
