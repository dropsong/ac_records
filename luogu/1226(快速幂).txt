#include<bits/stdc++.h>
using namespace std;
long long b,p,k;
long long POW(long long a,long long b)
{
    long long r=1,base=a;
    while(b!=0)
    {
    	if(b%2) r*=base;
    	base*=base;
    	b/=2;
    	r%=k; base%=k;
    }
    return r;
}
int main()
{
    scanf("%lld%lld%lld",&b,&p,&k);
    printf("%lld^%lld mod %lld=%d",b,p,k,POW(b,p));
    return 0;
}