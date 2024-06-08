#include<bits/stdc++.h>
using namespace std;
struct SB
{
    int t,
        index;
}a[1005];
int n;
double sum;
void input()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i].t);
        a[i].index=i;
    }
}
bool cmp(SB x,SB y)
{
    return x.t < y.t;
}
void output()
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",a[i].index);
        sum+=a[i].t*(n-i);
    }
    printf("\n%.2lf",sum/n);
}
int main()
{
    input();
    sort(a+1,a+1+n,cmp);
    output();
    return 0;
}