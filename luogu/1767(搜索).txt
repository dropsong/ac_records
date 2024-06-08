#include<bits/stdc++.h>
#define MAXN 210
using namespace std;

int n,m=-1,ans;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
int a[MAXN][MAXN];
string s;

int dfs(int x,int y)
{
    a[x][y]=0;
    for(int i=0;i<4;i++)
    {
        int nx=x+dir[i][0];
        int ny=y+dir[i][1];
        if(nx>=1&&nx<=n&&ny>=0&&ny<m&&a[nx][ny])
        dfs(nx,ny);
    }
}

int main()
{
    cin>>n;
    getline(cin,s);
    for(int i=1;i<=n;i++)
    {
        getline(cin,s);
        int len=s.size();
        m=max(m,len);
        for(int j=0;j<len;j++)
        if(s[j]>='a'&&s[j]<='z')
        a[i][j]=1;
    }
    
    for(int i=1;i<=n;i++)
    for(int j=0;j<m;j++)
    {
        if(a[i][j])dfs(i,j),ans++;
    }
    
    cout<<ans;
    return 0;
}