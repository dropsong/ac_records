#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int maxn=-1000000,temp,sum=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&temp);
        sum=max(sum+temp,temp);
        if(sum>maxn)maxn=sum;
    }
    printf("%d",maxn);
    return 0;
}