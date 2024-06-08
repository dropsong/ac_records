#include<bits/stdc++.h>
#define int long long
using namespace std;

const int MAXN =1e3+10;
bool matrix[MAXN][MAXN],vis[MAXN];
int n,t,h,r;

struct Point{
    int x,y,z;
}point[MAXN];

inline double sqr(int x){return x*x;}

inline bool oktogo(int x,int y)
{
    int x1=point[x].x,x2=point[y].x;
    int y1=point[x].y,y2=point[y].y;
    int z1=point[x].z,z2=point[y].z;
    double dis=sqrt(sqr(x1-x2)+sqr(y1-y2)+sqr(z1-z2));
    if(dis>double(r<<1))return false;
    else return true;
}

inline bool check(int x)
{
    if(point[x].z>=h-r)return true;
    else return false;
}

bool bfs()
{
    queue<int> qwq;
    for(int i=1;i<=n;i++)
    if(point[i].z<=r)
    {
        qwq.push(i); vis[i]=true;
        if(check(i)) return true;
    }
    
    while(!qwq.empty())
    {
        int head=qwq.front(); qwq.pop();
        for(int i=1;i<=n;i++)
        {
            if(vis[i])continue;
            if(matrix[head][i])
            {
                qwq.push(i);vis[i]=true;
                if(check(i))return true;
            }
        }
    }
    return false;
}

inline void init()
{
    for(int i=1;i<=n;i++)vis[i]=false;
    for(int i=1;i<=n;i++)
    for(int j=i;j<=n;j++)
    {
        matrix[i][j]=matrix[j][i]=false;
        if(oktogo(i,j))matrix[i][j]=matrix[j][i]=true;
    }
}

#undef int 
int main()
#define int long long
{
    cin>>t;
    while(t--)
    {
        cin>>n>>h>>r;
        int x,y,z;
        for(int i=1;i<=n;i++)
        {
            cin>>x>>y>>z;
            point[i].x=x;
            point[i].y=y;
            point[i].z=z;
        }
        init();
        if(bfs())printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
