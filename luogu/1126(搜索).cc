#include<iostream>
#include<queue>
using namespace std;

int n,m,sx,sy,ex,ey;
char face; bool ok=true;
int a[53][53],ans;
int fx[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
bool vis[53][53];
struct node{
    int x,y;
    int dir,step;
    bool chan;
};

inline int changedir(int dirt,int xia)
{
    if(xia==0)return (dirt+1)%4;
    else if(xia==233)return (dirt+2)%4;
    else return (dirt-1+4)%4;
}

inline bool check(int x,int y)
{
    if(x<1||x>=n||y<1||y>=m)return false;
    if(a[x][y]||a[x+1][y])return false;
    if(a[x][y+1]||a[x+1][y+1])return false;
    return true;
}

inline bool bfs()
{
    queue<node> qwq;
    node temp;
    temp.x=sx;temp.y=sy;
    if(face=='E')temp.dir=0;
    if(face=='S')temp.dir=1;
    if(face=='W')temp.dir=2;
    if(face=='N')temp.dir=3;
    temp.step=0; temp.chan=false;
    qwq.push(temp);
    vis[temp.x][temp.y]=true;
    
    while(!qwq.empty())
    {
        node head=qwq.front();
        qwq.pop();
        for(int i=1;i<=3;i++)
        {
            int nx=head.x+fx[head.dir][0]*i;
            int ny=head.y+fx[head.dir][1]*i;
            if(!check(nx,ny))break;
            if(vis[nx][ny])continue;
            if(nx==ex&&ny==ey)
            {
                ans=head.step+1;
                return true;
            }
            qwq.push((node){nx,ny,head.dir,head.step+1,false});
            vis[nx][ny]=true;
        }
        if(head.chan)continue;
        int dirti=changedir(head.dir,0);
        int dirti2=changedir(head.dir,1);
        qwq.push((node){head.x,head.y,dirti,head.step+1,true});
        qwq.push((node){head.x,head.y,dirti2,head.step+1,true});
        if(ok)
        {
        	ok=false;
        	int dirti3=changedir(head.dir,233);
        	qwq.push((node){head.x,head.y,dirti3,head.step+2,true});
        }
    }
    return false;
}

int main()
{
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    cin>>a[i][j];
    cin>>sx>>sy>>ex>>ey>>face;
    
    if(sx==ex&&sy==ey)cout<<0;
    else if(bfs())cout<<ans;
    else cout<<"-1";
    return 0;
}
