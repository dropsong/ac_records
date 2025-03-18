#include<bits/stdc++.h>
using namespace std;
int mi[105],ti[105];
int f[105][205][205];

inline int _max(int x,int y)
{return x>y? x : y;}

int F(int i,int m,int t)
{
    if(f[i][m][t])
        return f[i][m][t];
    if(i>0)
        if(m>=mi[i]&&t>=ti[i])
            f[i][m][t]=_max(F(i-1,m,t),F(i-1,m-mi[i],t-ti[i])+1);
        else
            f[i][m][t]=F(i-1,m,t);
    return f[i][m][t];
}

int main()
{
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;i++)
    scanf("%d%d",&mi[i],&ti[i]);
    printf("%d",F(n,m,t));
    return 0;
}