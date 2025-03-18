//每一个不曾AC的日子都是一种遗憾
#include<cstdio>
#include<queue>
#include<map>
#define MAXN 1010
using namespace std;

int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    int t,kase=0;
    while(scanf("%d",&t)==1&&t){
        printf("Scenario #%d\n",++kase);
        
        map<int,int>team;
        for(int i=0;i<t;i++)
        {
            int n,x;
            scanf("%d",&n);
            while(n--){
                scanf("%d",&x);
                team[x]=i;
            }
        }
    
        queue<int>qwq,qwq2[MAXN];
        for(;;){
            int x;
            char cmd[10];
            scanf("%s",cmd);
            
            if(cmd[0]=='S')break;
            
            else if(cmd[0]=='D'){
                int t=qwq.front();
                printf("%d\n",qwq2[t].front());
                qwq2[t].pop();
                if(qwq2[t].empty())qwq.pop();
            }
        
            else if(cmd[0]=='E'){
                scanf("%d",&x);
                int t=team[x];
                if(qwq2[t].empty())qwq.push(t);
                qwq2[t].push(x);
            }
        }
        printf("\n");
    }
    return 0;
} 