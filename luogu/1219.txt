#include<bits/stdc++.h>
using namespace std;
const int MAXN=15;
int n,a[MAXN],ans,sum;
bool used[MAXN],z[2*MAXN],f[2*MAXN];
void output()
{
    ans++;
    if(sum<3)
    {
        for(int k=1;k<=n;k++)
        {
            printf("%d ",a[k]);
        }
        printf("\n");
        sum++;
    }
}
void search(int i)
{
    for(int j=1;j<=n;j++)
    {
        if((!used[j])&&(!z[i+j])&&(!f[i-j+n]))
        {
            a[i]=j;
            used[j]=true;
            z[i+j]=true;
            f[i-j+n]=true;
            if(i==n) output();
            else search(i+1);
            used[j]=false;
            z[i+j]=false;
            f[i-j+n]=false;
        }
    }
}
int main()
{
    scanf("%d",&n);
    search(1);
    printf("%d",ans);
    return 0;
}