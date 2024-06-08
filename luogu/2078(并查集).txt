#include<bits/stdc++.h>
#define MAXN 10005
using namespace std;
int uset[3*MAXN];

void makeset(int size){
    for(int i=1;i<=size;i++)uset[i]=i;
}

int find(int x){
    if(uset[x]!=x)uset[x]=find(uset[x]);
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
    int n,m,p,q;
    cin>>n>>m>>p>>q;
    makeset(n+m);
    
    for(int i=1;i<=p;i++)
    {
        int x,y;
        cin>>x>>y;
        unionset(x,y);
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        unionset(n-x,n-y);
    }
    
    int ans1=0,ans2=0;
    for(int i=1;i<=n;i++)
        if(find(1)==find(i))ans1++;
    for(int i=n+1;i<=m+n;i++)
        if(find(n+1)==find(i))ans2++;
    
    
    cout<<min(ans1,ans2);
    return 0;
}