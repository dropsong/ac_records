#include<bits/stdc++.h>
using namespace std;
int minn=1000000001,maxn=-1;
int gcd(int x,int y)
{
    if(x==y)return x;
    else
    {
        if(x>y)return gcd(y,x);
        else
        {
            if(x%2==0)
            {
                if(y%2==0)return 2*gcd(x/2,y/2);
                else return gcd(x/2,y);
            }
            else
            {
                if(y%2==0)return gcd(x,y/2);
                else return gcd(x,y-x);
            }
        }
    }
}
int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>maxn)maxn=a;
    if(b>maxn)maxn=b;
    if(c>maxn)maxn=c;
    if(a<minn)minn=a;
    if(b<minn)minn=b;
    if(c<minn)minn=c;
    int temp=minn;
    minn=minn/gcd(minn,maxn);
    maxn=maxn/gcd(temp,maxn);
    printf("%d/%d",minn,maxn);
    return 0;
}