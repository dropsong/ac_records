//also see:ISBN 978-7-302-35628-8(P163)
#include<stdio.h>
#include<cstring>
const int MAXN=100+5;

char pic[MAXN][MAXN];
int m,n,idx[MAXN][MAXN];

void DFS(int r,int c,int id)
{
    if(r<0||r>=m||c<0||c>=n)return;
    if(idx[r][c]>0||pic[r][c]!='@')return;
    idx[r][c]=id;
    for(int delta_r=-1;delta_r<=1;delta_r++)
    for(int delta_c=-1;delta_c<=1;delta_c++)
    if(delta_r||delta_c)DFS(r+delta_r,c+delta_c,id);
}

int main()
{
    while(scanf("%d%d",&m,&n)==2&&m&&n)
    {
        for(int i=0;i<m;i++)scanf("%s",pic[i]);
        memset(idx,0,sizeof(idx));
        int cnt=0;
        for(int i=0;i<m;i++)
        for(int j=0;j<n;j++)
        if(idx[i][j]==0&&pic[i][j]=='@')
        DFS(i,j,++cnt);
        printf("%d\n",cnt);
    }
    
    return 0;
}
