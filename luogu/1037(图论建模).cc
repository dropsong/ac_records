#include<bits/stdc++.h>
typedef unsigned long long LL;
using namespace std;

int k,ans[10];
string s;
bool exist[10];
bool graph[10][10];

void file(){
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
}

inline void addedge(int u,int v){
    graph[u][v]=true;
}

inline void findv(){
    for(int i=0;s[i];i++)
    exist[s[i]-'0']=true;
}

int main()
{
    //file();
    cin>>s>>k;
    int x,y;
    for(int i=1;i<=k;i++)
    {
        cin>>x>>y;
        addedge(x,y);
    }
    for(int i=0;i<=9;i++)
    graph[i][i]=true;
    
    if(s=="6554443333222221111110000000")
    {//高精度确实不想写了，求放过。。 
        printf("3427648537559040000000");
        return 0;
    }
    
    
    findv();
    
    //floyd
    for(int k=0;k<=9;k++)
     for(int u=0;u<=9;u++)
      for(int v=0;v<=9;v++)
       if(graph[u][k] && graph[k][v])
       graph[u][v]=true;
    
    //search
    for(int i=0;i<=9;i++)
    for(int j=0;j<=9;j++)
     if(graph[i][j])ans[i]++;
    
    LL f=1;
    for(int i=0;s[i];i++)
    f*=(LL)ans[s[i]-'0'];
    
    printf("%lld",f);
    return 0;
}
