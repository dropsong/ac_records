#include<stdio.h>
#define RP INT_MAX
#define MAXN 5010
using namespace std;
int uset[MAXN];

void makeset(int size){
    for(int i=0;i<size;i++)uset[i]=i;
}

inline int find(int x){
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
    int n,m,p;
    scanf("%d%d%d",&n,&m,&p);

    makeset(n+1);
    int mi,mj;
    while(m--){
        scanf("%d%d",&mi,&mj);
        unionset(mi,mj);
    }

    int pi,pj;
    while(p--){
    	scanf("%d%d",&pi,&pj);
        if(find(pi)==find(pj))
        printf("Yes\n");
        else printf("No\n");
    }

    return 0;
}