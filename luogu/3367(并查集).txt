#include<stdio.h>
#include<iostream>
#define RP INT_MAX
using namespace std;
const int MAXN=10010;
int uset[MAXN];

void makeset(int size){
    for(int i=0;i<size;i++)uset[i]=i;
}

int find(int x){
    if(x!=uset[x])uset[x]=find(uset[x]);
    return uset[x];
}

void unionset(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    uset[x]=y;
}


int main()
{
    //freopen(".in","r",stdin);
    //freopen(".out","w",stdout);
    
    int n,m;
    cin>>n>>m;
    makeset(n+1);
    int z,x,y;
    while(m--)
    {
        scanf("%d%d%d",&z,&x,&y);
        if(z==1)unionset(x,y);
        else if(z==2){
            if(find(x)==find(y))
            printf("Y\n");
            else printf("N\n");
        }
    }
    
    return 0;
}