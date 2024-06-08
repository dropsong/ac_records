#include<cstdio>
#include<cstring>
#define MOD 100000000
using namespace std;

int m,n,maxn,top,Soil[25];//每行土地的情况

int main()
{
    scanf("%d%d",&m,&n); maxn=1<<n;
    int Type[maxn+10];//储存压缩后的每行可能的状态
    int f[20][maxn+10];
    for(int i=0;i<maxn;i++)
    {//存储每行可能的状态
        if(i&(i<<1))continue;
        Type[++top]=i;
    }
    
    for(int i=1;i<=m;i++)
    for(int l=1;l<=n;l++)
    {
        int k; scanf("%d",&k);
        if(!k)Soil[i]+=1<<(n-l);//反向建图,0置为1,和Type数组中情况相对,便于使用位运算检查
        //因为先读入的是左侧的土地，二进制中左侧的'1'代表的值更大,所以将第l个读入的数存在第l位应+(1<<(n-l))
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=top;i++)
    if(!(Type[i]&Soil[1])) f[1][i]=1;
    
    for(int i=2;i<=m;i++)//穷举层数
    for(int l=1;l<=top;l++){//穷举本层
        if(Type[l]&Soil[i])continue;//判断是否符合
        for (int j=1;j<=top;j++){//穷举上一层
            if (Type[j]&Soil[i-1]) continue;//判断是否符合
            if (Type[l]&Type[j]) continue;//判断是否符合
            f[i][l]=(f[i][l]+f[i-1][j])%MOD;
        }
    }
    
    int ans=0;
    for(int i=1;i<=top;i++)
    ans=(ans+f[m][i])%MOD;//累加答案
    
    printf("%d",ans);
    return 0;
}
