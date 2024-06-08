#include<bits/stdc++.h>
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
using namespace std;

const int MAXN = 105;
const int INF = 0x7fffffff;
int f[MAXN<<1][MAXN<<1],n;
int F[MAXN<<1][MAXN<<1];
int a[MAXN<<1],sum[MAXN<<1];

int dp(int i,int j)   //max
{
    if(f[i][j])return f[i][j];
    for(int k=i;k<j;k++)
    f[i][j]=max(f[i][j],dp(i,k)+dp(k+1,j)+sum[j]-sum[i-1]);
    return f[i][j];
}

int DP(int i,int j)   //min
{
    if(F[i][j]!=INF)return F[i][j];
    for(int k=i;k<j;k++)
    F[i][j]=min(F[i][j],DP(i,k)+DP(k+1,j)+sum[j]-sum[i-1]);
    return F[i][j];
}

int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        sum[i]=sum[i-1]+a[i];
        a[i+n]=a[i];
    }
    for(int i=n+1;i<=2*n;i++)
    sum[i]=sum[i-1]+a[i];
    
    for(int i=1;i<=2*n;i++)
    for(int j=1;j<=2*n;j++)
    {
    	F[i][j]=INF;
    	if(i==j)F[i][j]=0;
    }
    
    dp(1,n<<1);DP(1,n<<1);
    int ans1=INF,ans2=0;
    for(int i=1;i<=n;i++)
    ans1=min(ans1,F[i][n+i-1]),
    ans2=max(ans2,f[i][n+i-1]);
    
    printf("%d\n%d",ans1,ans2);
    return 0;
}
