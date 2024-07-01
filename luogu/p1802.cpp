#include <cstdio>
#define MAX(a,b) ((a)>(b)?(a):(b))

const int MAXN = 1e3+5;
int f[MAXN][MAXN],lose[MAXN],win[MAXN],use[MAXN];

int dp(int n, int w){
    if(n<=0) return 0;
    if(f[n][w]) return f[n][w];
    if(!use[n]){  // win without drug
        f[n][w] = dp(n-1,w) + win[n];
        return f[n][w];
    }
    if(!w){
        f[n][w] = dp(n-1,0) + lose[n];
        return f[n][w];
    }
    int temp1 = dp(n-1,w) + lose[n];
    int temp2 = (w-use[n]>=0)?(dp(n-1,w-use[n]) + win[n]):0;
    f[n][w] = MAX(temp1, temp2);
    return f[n][w];
}

int main(){
    int n, x;
    scanf("%d%d",&n,&x);
    
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&lose[i],&win[i],&use[i]);
    }

    printf("%lld",5ll*dp(n,x));
    return 0;
}