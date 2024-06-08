#include<iostream>
#include<cstdio>
#include<algorithm>
#define LL long long
using namespace std;

LL T,t;
LL a,b,c,d,ans;

inline LL gcd(LL x,LL y)
{
    LL i,j;
    if(x==0)return y;
    if(y==0)return x;
    for(i=0;0==(x&1);++i)x>>=1;
    for(j=0;0==(y&1);++j)y>>=1;
    if(j<i)i=j;
    while(1){
        if(x<y)swap(x,y);
        if(0==(x-=y))return y<<i;
        while(0==(x&1))x>>=1;
    }
}

inline LL lcm(LL x,LL y){return x*y/gcd(x,y);}

int main()
{
    scanf("%lld",&T);
    for(LL i=1;i<=T;i++)
    {
        ans=0;
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        for(LL j=1;j*j<=d;j++)
        {
            if(!(d%j))
            {
                if(gcd(j,a)==b&&lcm(j,c)==d)ans++;
                if(d/j!=j)
                if(gcd(d/j,a)==b&&lcm(d/j,c)==d)ans++;
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
