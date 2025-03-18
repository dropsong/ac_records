#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int main()
{
    int r;
    scanf("%d",&r);
    for(int i=1;i<=r;i++)
    {
        for(int j=1;j<=i;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(int i=r-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        {
            a[i][j]+=max(a[i+1][j],a[i+1][j+1]);
        }
    }
    printf("%d",a[1][1]);
    return 0;
}