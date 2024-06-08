#include<stdio.h>
#include<algorithm>
#define MAXN 1000005
#define HOME
#define TEST printf("a test.\n")
using namespace std;

struct node
{
    int front;
    int rear;
};
node a[MAXN];

bool cmp(node x,node y)
{
    return (x.rear<y.rear);
}


int main()
{
#ifdef NOIP
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    
    int n;
    scanf("%d",&n);
    
    for(register int i=1;i<=n;i++)
    {
        scanf("%d%d",&a[i].front,&a[i].rear);
    }
    sort(a+1,a+1+n,cmp);
    
    int ocrupy=-1,sum=0;
    for(register int i=1;i<=n;i++)
    {
        if(a[i].front>=ocrupy){
            sum++;
            ocrupy=a[i].rear;
        }
        else continue;
    }
    
    printf("%d",sum);
    
    return 0;
}