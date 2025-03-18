#include<stdio.h>
#include<algorithm>
#define HOME
#define MAXN 200010
#define TEST printf("a test.\n")
using namespace std;
int ans[MAXN];
int top;
int main()
{
#ifdef NOIP
    freopen(".in","r",stdout);
    freopen(".out","w",stdout);
#endif
    
    int n,flag,x;
    scanf("%d",&n);
    ans[0]=0;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&flag);
        if(flag==0){
            scanf("%d",&x);
            ans[++top]=max(ans[top-1],x);
        }
        else if(flag==1){
            if(top) top--;
        }
        else {
            printf("%d\n",ans[top]);
        }
    }
    
    return 0;
}