//https://www.luogu.org/problemnew/show/UVA1025
#include<bits/stdc++.h>
using namespace std;
int dp[220][55];
int visit[220][55][2];
int t[220],d1[55],d2[55];
const int INF = 0x3f3f3f3f;
int main()
{
    int n,T;
    int M1,M2;
    int k=1;
    while(~scanf("%d",&n)&&n){
        scanf("%d",&T);
        for(int i=1;i<n;i++) scanf("%d",&t[i]);
        scanf("%d",&M1);
        for(int i=1;i<=M1;i++) scanf("%d",&d1[i]);
        scanf("%d",&M2);
        for(int i=1;i<=M2;i++) scanf("%d",&d2[i]);
        memset(visit,0,sizeof(visit));
        for(int i=1;i<=M1;i++) {
            visit[d1[i]] [1][0]=1;
            int temp=d1[i];
            for(int j=1;j<n;j++){
                temp+=t[j];
                if(temp<=T) visit[temp][j+1][0]=1;
                else break;
            }
        }
          for(int i=1;i<=M2;i++) {
            visit[d2[i]] [n][1]=1;
            int temp=d2[i];
            for(int j=n-1;j>1;j--){
                temp+=t[j];
                if(temp<=T) visit[temp][j][1]=1;
                else break;
            }
        }
        for(int i=1;i<=n;i++) dp[T][i]=INF;
        dp[T][n]=0;
        for(int i=T-1;i>=0;i--){
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i+1][j]+1;
                if(j<n&&visit[i][j][0]&&i+t[j]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j]][j+1]);
                if(j>1&&visit[i][j][1]&&i+t[j-1]<=T)
                    dp[i][j]=min(dp[i][j],dp[i+t[j-1]][j-1]);
            }
        }
        if(dp[0][1]>=INF)
            printf("Case Number %d: impossible\n",k++);
        else printf("Case Number %d: %d\n",k++,dp[0][1]);

    }
    return 0;
}
