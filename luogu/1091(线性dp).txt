//每一个不曾AC的日子都是一种遗憾 
#include<cstdio>
#include<algorithm>
using namespace std;

int n,ans;
int a[105],f[2][105];

void file(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}

inline void input(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    scanf("%d",&a[i]);
}

int main()
{
    //file();
    input();
    a[0]=0;
    for(int i=1;i<=n;i++) 
    for(int j=0;j<i;j++)
    if(a[i]>a[j])
    f[0][i]=max(f[0][i],f[0][j]+1);
    
    a[n+1]=0;
    for(int i=n;i;i--)
    for(int j=n+1;j>i;j--)
    if(a[i]>a[j])
    f[1][i]=max(f[1][i],f[1][j]+1);
    
    for(int i=1;i<=n;i++)
    ans=max(f[0][i]+f[1][i]-1,ans); 
    
    printf("%d\n",n-ans);
    return 0;
}