#include<bits/stdc++.h>
using namespace std;
int n,sum;
int a[]={6,2,5,5,4,5,6,3,7,6};
int work(int x)
{
    if(x==0)return a[0];
    int SUM=0;
    while(x>0)
    {
        SUM+=a[x%10];
        x/=10;
    }
    return SUM;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<=1000;i++)
    {
        for(int j=0;j<=1000;j++)
        {
            if(work(i)+work(j)+work(i+j)+4==n)
            sum++;
        }
    }
    printf("%d",sum);
    return 0;
}