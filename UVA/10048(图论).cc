#include<stdio.h>
#include<algorithm>
#define MAXN 105
using namespace std;

const int INF=0xfffffff;
int c,s,q;
int data[MAXN][MAXN];

int main()
{
    int t=0;
    while(scanf("%d%d%d",&c,&s,&q)==3){
        if(c==0&&s==0&&q==0)break;
        if(t)printf("\n");
        
        for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
        data[i][j]=INF;
        
        int x,y,z;
        for(int i=0;i<s;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            data[x][y]=data[y][x]=z;
        }
        
        for(int k=1;k<=c;k++)
         for(int i=1;i<=c;i++)
          for(int j=1;j<=c;j++)
           data[i][j]=min(data[i][j],max(data[i][k],data[k][j]));
           
        printf("Case #%d\n",++t);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            if(data[x][y]==INF)printf("no path\n");
            else printf("%d\n",data[x][y]);
        }
    }
    
    return 0;
}