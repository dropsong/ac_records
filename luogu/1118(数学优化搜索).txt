// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;

int n,sum;
int a[20];
int yh[20][20];

int main()
{
    cin>>n>>sum;
    
    yh[1][1]=1; 
    for(int i=2;i<=n;i++) 
    for(int j=1;j<=i;j++)
    yh[i][j]=yh[i-1][j-1]+yh[i-1][j];
    
    for(int i=1;i<=n;i++)
    a[i]=i;
    do
    {
        int ans=0;
        for(int i=1;i<=n;i++)
        ans+=yh[n][i]*a[i];
        
        if(ans==sum)
        {
            for(int i=1;i<=n;i++)
            cout<<a[i]<<" ";
            return 0;
        }
        
    }while(next_permutation(a+1,a+1+n));
    
    return 0;
}
