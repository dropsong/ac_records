//thoughts by lrj.
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

struct node{
    int v[3],dist;
    bool operator<(const node& rhs)const{
        return dist>rhs.dist;
    }
};

const int MAXN =200+5;
int vis[MAXN][MAXN],cap[3],ans[MAXN];

void update_ans(const node&u)
{
    for(int i=0;i<3;i++){
        int d=u.v[i];
        if(ans[d]<0||u.dist<ans[d])ans[d]=u.dist;
    }//如果没有到达d或者找到更好的答案，更新。 
}

void solve(int a,int b,int c,int d)
{
    cap[0]=a; cap[1]=b; cap[2]=c;
    memset(vis,0,sizeof(vis));
    memset(ans,-1,sizeof(ans));
    priority_queue<node> qwq;
    
    node start;
    start.dist=0;
    start.v[0]=0; start.v[1]=0; start.v[2]=c;
    qwq.push(start); vis[0][0]=1;
    
    while(!qwq.empty())
    {
        node u=qwq.top(); qwq.pop();
        update_ans(u);
        if(ans[d]>=0)break;  //如果已经达到要求，退出。 
        for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
        if(i!=j){                 //由i倒向j 
            if(u.v[i]==0||u.v[j]==cap[j])continue;//不能倒了
            int amount=min(cap[j]-u.v[j],u.v[i]);
            node u2;
            memcpy(&u2,&u,sizeof(u));
            u2.dist=u.dist+amount;
            u2.v[i]-=amount; u2.v[j]+=amount;
            if(!vis[u2.v[0]][u2.v[1]])
            {
                vis[u2.v[0]][u2.v[1]]=1;
                qwq.push(u2);
            }
        }
    }
    
    while(d>=0)
    {
        if(ans[d]>=0){
            printf("%d %d\n",ans[d],d);
            return;
        }
        d--;
    }
}

int main()
{
    int t,a,b,c,d;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d%d",&a,&b,&c,&d);
        solve(a,b,c,d);
    }
    
    return 0;
}
