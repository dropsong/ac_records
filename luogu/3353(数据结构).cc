/***********hack*input************
5 3
2 1
3 1
4 1
5 1
101 100
*********************************/
#include<cstdio>
#define lowbit(x) ((x)&(-x))
#define MAX(a,b) ((a)>(b)?(a):(b))
using namespace std;

const int MAXN = 100005;
int c[MAXN],n,w;

int sum(int i){
    int s=0;
    while(i>0){
        s+=c[i];
        i-=lowbit(i);
    }
    return s;
}

void update(int i,int value){
    while(i<=n){
        c[i]+=value;
        i+=lowbit(i);
    }
}

int main()
{
    scanf("%d%d",&n,&w);
    for(int i=1;i<=n;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        update(x,y);
    }
    
    int ans=0;
    for(int i=w;i<=n;i++)
    ans=MAX(ans,sum(i)-sum(i-w));
    
    printf("%d",ans);
    return 0;
}