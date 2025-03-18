#include<bits/stdc++.h>
#define MAXN 105
using namespace std;

int ANS=-9999,n,m;
int a[MAXN][MAXN];
int s[MAXN][MAXN];

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
        s[i][j]=s[i][j-1]+s[i-1][j]-s[i-1][j-1]+a[i][j];
    }

    //=========test==========
    
    
    
    //=========test==========
    
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    {
        for(int k=1;k<=i;k++)
        for(int o=1;o<=j;o++)
        {
            //cout<<"i,j="<<i<<","<<j<<endl;
            //cout<<"k,o="<<k<<","<<o<<endl;
            
            int ans=s[i][j]-s[i][o-1]-s[k-1][j]+s[k-1][o-1];
            //cout<<"ans="<<ans<<" ";
            
            if(ans==(i-k+1)*(i-k+1)&&ans==(j-o+1)*(j-o+1))
            ANS=max(ANS,(int)sqrt(ans));
            //cout<<"ANS="<<ANS<<endl;
            //system("pause");
        }
    }
    printf("%d",ANS);
    return 0;
}