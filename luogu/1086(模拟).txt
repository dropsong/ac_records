#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;

int m,n,k,remain;
int s[25][25];
int total;
int id=1;

struct coordinate
{
    int x;
    int y;
    int num;
}ss[500];
bool cmp(coordinate a, coordinate b)
{
    return a.num>b.num; 
}

inline void input()
{
    scanf("%d%d%d",&m,&n,&k);
    remain=k;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&s[i][j]);
            if(s[i][j])
            {
                ss[id].x=i;
                ss[id].y=j;
                ss[id].num=s[i][j];
                id++;
            }
        }
        id--;
}

inline int Manhattan(coordinate a,coordinate b)
{
    return (abs(a.x-b.x)+abs(a.y-b.y));
}

void dfs(int step)
{
    int tmp,dist;
    if(step>id)
        return;
    if(step==1)
        dist=ss[1].x;
    else
        dist=Manhattan(ss[step-1],ss[step]);
    tmp=remain-dist-1;
    if(tmp>=ss[step].x)
    {
        total+=ss[step].num;
        remain=remain-dist-1;
        dfs(step+1);
    }
    return;
}

int main()
{
    input();
    sort(ss+1,ss+id+1,cmp);
    dfs(1);
    printf("%d",total);
    return 0;
}