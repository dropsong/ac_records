#include<bits/stdc++.h>
using namespace std;

const int MAXN = 20+5;
int n,w[MAXN],ans,f[MAXN],son[MAXN];
bool matrix[MAXN][MAXN];

int dp(int x)
{
    if(f[x])return f[x];
    int sum=0,tempi=0;
    for(int i=1;i<=n;i++)
    if(matrix[x][i])
    {
        int temp=sum;
        sum=max(dp(i),sum);
        if(sum!=temp)tempi=i;
    }
    son[x]=tempi;
    f[x]=sum+w[x];
    return f[x];
}

inline void print_way(int x)
{
    printf("%d ",x);
    if(son[x])print_way(son[x]);
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)cin>>w[i];
    for(int i=1;i<n;i++)
    for(int j=i+1;j<=n;j++)
    scanf("%d",&matrix[i][j]);
    
    int tempi;
    for(int i=1;i<=n;i++)
    {
        int yswywb=ans;
        ans=max(dp(i),ans);
        if(ans!=yswywb)tempi=i;
    }
    
    print_way(tempi);
    cout<<endl<<ans;
    return 0;
}
