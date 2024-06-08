//每一个不曾AC的日子都是一种遗憾
#include<bits/stdc++.h>
#define maxn 100010
using namespace std;

int q[maxn],head=0,tail=0,k,x,p,f[maxn];

inline void BFS()
{
    int t,y;
    tail=0;
    head=1;
    q[++tail]=x;
    
    while(head<=tail)
    {
        int t=q[head];
        y=2*t;
        if(y>=0&&y<=maxn&&(f[y]==-1||f[y]>f[t]+1)) 
        {
            q[++tail]=y;
            f[y]=f[t]+1;
        }
        y=t+1;
        if(y>=0&&y<=maxn&&(f[y]==-1||f[y]>f[t]+1))
        {
            q[++tail]=y;
            f[y]=f[t]+1;
        }
        y=t-1;
        if(y>=0&&y<=maxn&&(f[y]==-1||f[y]>f[t]+1))
        {
            q[++tail]=y;
            f[y]=f[t]+1;
        }       
        ++head;
    }
} 
int main()
{
    cin>>k;
    while(k--)
    {
        cin>>x>>p;
        memset(f,-1,sizeof(f));
        f[x]=0;
        BFS();
        printf("%d\n",f[p]);
    }
    return 0;
}