#include<bits/stdc++.h>
using namespace std;
char a[101][101];
int b[101][101]; 
char c[7]="izhong";
int dir[8][2]={1,0,0,1,1,1,1,-1,-1,1,-1,-1,0,-1,-1,0};
int dx,dy;
int n;
void Ranse(int x,int y,int step,int fang) 
{
    if(step>=7) return; 
    b[x][y]=1; 
    dx=x+dir[fang][0];
    dy=y+dir[fang][1];
    Ranse(dx,dy,step+1,fang);
} 
void dfs1(int x,int y,int step,int fang)
{
    if(x<0||y<0||x>n||y>n) return;
    if(step>=6)
    {
        Ranse(x,y,0,7-fang); return;
    }
    dx=x+dir[fang][0];
    dy=y+dir[fang][1];
    if(a[dx][dy]!=c[step]) return;
    else dfs1(dx,dy,step+1,fang);
}
void dfs2() 
{
    for(int i=1;i<=n;i++)
      for(int j=0;j<n;j++) 
      {
          if(a[i][j]=='y')
          {
              for(int k=0;k<=7;k++)
               dfs1(i,j,0,k); 
          }
      }
} 
int main() 
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%s",a[i]);
    dfs2(); 
    for(int i=1;i<=n;i++)
    {
      for(int j=0;j<n;j++)
       if(b[i][j]==1)printf("%c",a[i][j]); 
       else printf("*");
      
      printf("\n");
    }
    return 0;
}